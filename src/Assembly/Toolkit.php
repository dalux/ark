<?php

namespace Brisk\Assembly;

use Brisk\Exception\CoreException;

class Toolkit
{

    /**
     * 取参数中第一个非空字符
     *
     * @access public
     * @static
     * @return mixed
     */
    static function choose()
    {
        $args = func_get_args();
        if (func_num_args() < 2) {
            return $args;
        }
        $target = null;
        foreach ($args as $v) {
            if (trim($v) != '') {
                $target = $v;
                break;
            }
        }
        return $target;
    }

    /**
     * 获取Print_r方法后产生的字符串
     *
     * @access public
     * @static
     * @return string
     */
    static function sprintr()
    {
        $args = func_get_args();
        ob_start();
        foreach ($args as $arg) {
            print_r($arg);
            echo PHP_EOL;
        }
        return preg_replace("/\\]\\=\\>\\n(\\s+)/m", "] => ", ob_get_clean());
    }

    /**
     * 直接将Print_r方法结果输出到页面
     *
     * @access public
     * @static
     * @return null
     */
    static function printr()
    {
        $params = func_get_args();
        $result = call_user_func_array(array(__CLASS__, 'Sprintr'), $params);
        echo sprintf('<pre>%s</pre>', htmlspecialchars($result));
    }

    /**
     * 获取var_dump方法后产生的字符串
     *
     * @access public
     * @static
     * @return string
     */
    static function svardump()
    {
        $args = func_get_args();
        ob_start();
        foreach ($args as $arg) {
            var_dump($arg);
        }
        return preg_replace("/\\]\\=\\>\\n(\\s+)/m", "] => ", ob_get_clean());
    }

    /**
     * 直接将var_dump方法结果输出到页面
     *
     * @access public
     * @static
     * @return null
     */
    static function vardump()
    {
        $params = func_get_args();
        $result = call_user_func_array(array(__CLASS__, 'Svardump'), $params);
        echo sprintf('<pre>%s</pre>', htmlspecialchars($result));
    }

    /**
     * 按字段排序数组
     *
     * @param array $data
     * @param $key
     * @param string $sort
     * @return array
     */
    static function sortArray(array $data, $key, $sort = 'asc')
    {
        $keys = array();
        foreach ($data as $k=> $v) {
            $keys[$k] = $v[$key];
        }
        $func = $sort == 'asc' ? 'asort' : 'arsort';
        $func($keys);
        $result = array();
        foreach ($keys as $k=> $v) {
            $result[$k] = $data[$k];
        }
        return $result;
    }

    /**
     * 创建目录文件夹，可同时创建多级
     *
     * @access public
     * @static
     * @param string $dir
     * @return bool
     * @throws CoreException
     */
    static function mkDir($dir)
    {
        if (!($dir = trim($dir))) {
            throw new CoreException(Language::get('tbox.invalid_create_path'));
        }
        $dirs = array($dir);
        while (!file_exists($dir)) {
            $dir = dirname($dir);
            $dirs[] = $dir;
        }
        if (count($dirs)>1) {
            $dirs = array_reverse($dirs);
            foreach ($dirs as $k=> $v) {
                $v = rtrim($v, DIRECTORY_SEPARATOR);
                if (!file_exists($v) && !@mkdir($v, 0777)) {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * 递归拷贝目录
     *
     * @param $src
     * @param $dst
     * @throws CoreException
     */
    static function copyDir($src, $dst)
    {
        $handle = opendir($src);
        self::mkDir($dst);
        while (false !== ($file = readdir($handle))) {
            if (($file != '.') && ($file != '..')) {
                if (is_dir($src. DIRECTORY_SEPARATOR. $file)) {
                    self::copyDir($src. DIRECTORY_SEPARATOR. $file, $dst. DIRECTORY_SEPARATOR. $file);
                } else {
                    copy($src. DIRECTORY_SEPARATOR. $file, $dst. DIRECTORY_SEPARATOR. $file);
                }
            }
        }
        closedir($handle);
    }

    /**
     * 递归删除目录
     *
     * @static
     * @param $dirName
     * @return bool
     * @throws CoreException
     */
	static function removeDir($dirName)
	{
		if (is_dir($dirName)) {
			$handle = opendir($dirName);
			while(($file = readdir($handle)) !== false) {
				if($file != '.' && $file != '..') {
					$dir = $dirName . '/' . $file;
					is_dir($dir) ? self::removeDir($dir) : unlink($dir);
				}
			}
			closedir($handle);
			return rmdir($dirName);
		}
	}

    /**
     * 转换编码
     *
     * @access public
     * @static
     * @param mixed  $content 要转换的内容
     * @param string $to_encoding 转到编码
     * @param string $from_encoding 来源编码
     * @return mixed
     */
    static function transEncoding($content, $to_encoding, $from_encoding = null)
    {
        if (is_array($content)) {
            while (list($k, $v) = each($content)) {
                $content[$k] = self::transEncoding($v, $to_encoding, $from_encoding);
            }
            return $content;
        }
        if (extension_loaded('mbstring')) {
            $from_encoding || $from_encoding = mb_detect_encoding($content, array('UTF-8', 'GB2312', 'ASCII'));
            return mb_convert_encoding($content, $to_encoding, $from_encoding);
        }
        $from_encoding || $from_encoding = self::detectEncoding($content);
        return iconv($from_encoding, $to_encoding, $content);
    }

    /**
     * 截字
     *
     * @access public
     * @static
     * @param $content
     * @param int $length
     * @param string $etc
     * @return string
     */
    static function truncate($content, $length, $etc = '...')
    {
        //如果存在mbstring扩展
        if (extension_loaded('mbstring')) {
            if (mb_strlen($content) > $length) {
                $length -= min($length, mb_strlen($etc));
                $encoding = mb_detect_encoding($content, array('UTF-8', 'GB2312', 'ASCII'));
                $content = mb_substr($content, 0, $length, $encoding). $etc;
            }
            return $content;
        }
        //如果没有，则手动检测编码
        $encoding = self::detectEncoding($content);
        if ($encoding != 'GB2312') {
            $content = iconv($encoding, 'GB2312', $content);
        }
        $substrlen = 0;
        $len = 0;
        for ($i = 0; $i < strlen($content); $i++) {
            if (ord($content[$i]) < 128) {
                $substrlen += 1;
            } else {
                $substrlen += 2;
            }
            $len += 1;
            if (($len+(strlen($etc))) >= $length) {
                break;
            }
        }
        $content = substr($content, 0, $substrlen). $etc;
        $content = iconv('GB2312', $encoding, $content);
        return $content;
    }

    /**
     * 检测字符串所用编码
     *
     * @access public
     * @static
     * @param string $string
     * @return string
     */
    static function detectEncoding($string)
    {
        $encoding = "ASCII";
        for ($i=0; $i<strlen($string); $i++) {
            if (ord($string[$i]) < 128) {
                continue;
            } elseif((ord($string{$i}) & 224) == 224) {
                $char = $string[++$i];
                if((ord($char) & 128) == 128) {
                    $char = $string[++$i];
                    if((ord($char) & 128) == 128) {
                        $encoding = "UTF-8";
                        break;
                    }
                }
            } elseif((ord($string[$i]) & 192) == 192) {
                $char = $string[++$i];
                if((ord($char) & 128) == 128) {
                    $encoding = "GB2312";
                    break;
                }
            }
        }
        return $encoding;
    }

    /**
     * 格式化时间
     *
     * @access public
     * @param int $time 时间戳
     * @return string
     */
    static function formatTime($time)
    {
        $date = array(
            378432000=> '年',
            1036800=> '月',
            86400=> '天',
            3600=> '小时',
            60=> '分',
            1=> '秒'
        );
        $str = '';
        foreach ($date as $k=> $v) {
            if ($time > $k) {
                $str.= floor($time/$k). $v;
                $time %= $k;
            }
        }
        return $str;
    }

    /**
     * 格式化大小数据
     *
     * @access public
     * @param integer $size
     * @return string
     */
    static function formatSize($size)
    {
        $prec = 3;
        $size = round(abs($size));
        $units = array('B', 'KB', 'MB', 'GB', 'TB');
        if (!$size) {
            return str_repeat(' ', $prec). '0'. $units[0];
        }
        $unit = min(4, floor(log($size)/log(2)/10));
        $size = $size*pow(2, -10*$unit);
        $digi = $prec-1- floor(log($size)/log(10));
        $size = round($size*pow(10, $digi))*pow(10, -$digi);
        return $size. $units[$unit];
    }

    /**
     * 取得随机字符串
     *
     * @access public
     * @param integer $length 取值长度
     * @param bool $onlynum 是否只取数字
     * @return string
     */
    static function random($length = 4, $onlynum = false)
    {
        $lower = range('a', 'z');
        $upper = range('A', 'Z');
        $numer = range(0, 9);
        $prepares = $onlynum ? $numer : array_merge($numer, $lower, $upper);
        shuffle($prepares);
        $offset = rand(0, count($prepares) - $length);
        return $length ? implode('', array_slice($prepares, $offset, $length)) : '';
    }

    /**
     * 去除数据两端空格
     *
     * @access public
     * @param mixed $content 要转换的内容
     * @return mixed
     */
    static function trim($content)
    {
        if (is_array($content)) {
            while (list($k, $v) = each($content)) {
                $content[$k] = self::trim($v);
            }
            return $content;
        }
        return trim($content);
    }

    /**
     * 编码字符串中的html代码
     *
     * @access public
     * @param mixed $content 要转换的内容
     * @param bool $encoding
     * @return mixed
     */
    static function htmlEncode($content, $encoding = true)
    {
        if (is_array($content)) {
            while (list($k, $v) = each($content)) {
                $content[$k] = self::htmlEncode($v, $encoding);
            }
            return $content;
        }
        $content = $encoding
            ? htmlspecialchars($content)
            : htmlspecialchars_decode($content);
        return trim($content);
    }

    /**
     * 判断是否是email地址
     *
     * @access public
     * @static
     * @param string $email
     * @return bool
     */
    static function isEmail($email)
    {
        return filter_var($email, FILTER_VALIDATE_EMAIL);
    }

    /**
     * 判断是否是手机号码
     *
     * @access public
     * @static
     * @param string $mobile
     * @return bool
     */
    static function isMobile($mobile)
    {
        if (!is_numeric($mobile)) return false;
        return preg_match('#^13[\d]{9}$|^14[5,7]{1}\d{8}$|^15[^4]{1}\d{8}$|^17[0,6,7,8]{1}\d{8}$|^18[\d]{9}$#', $mobile) ? true : false;
    }

    /**
     * 将XML字符串转换为XML对象
     *
     * @access public
     * @param string $content
     * @throws Exception
     * @return \SimpleXMLElement
     */
    static function strToXml($content)
    {
        libxml_use_internal_errors(true);
        if (!$data = simplexml_load_string($content, 'SimpleXMLElement', LIBXML_NOCDATA)) {
            $error = libxml_get_last_error();
            libxml_clear_errors();
            throw new Exception(Language::get('tbox.parse_string_failed', $error ? $error->message : '未知错误', $content));
        }
        return $data;
    }

    /**
     * 转换XML内容到数组
     *
     * @static
     * @access public
     * @param \SimpleXMLElement $object
     * @return array
     */
    static function xmlToArray(\SimpleXMLElement $object)
    {
        $i = 0;
        $return = array();
        $last_name = null;
        foreach ($object->children() as $val) {
            /* @var \SimpleXMLElement $val */
            if (isset($last_name) && $val->getName() == $last_name) {
                $i == 1 && $return[$last_name] = array($return[$last_name]);
                array_push($return[$last_name], self::xmlToArray($val));
            } else {
                $last_name = $val->getName();
                $return[$last_name] = count($val->children()) == 0
                    ? $val. ''
                    : self::xmlToArray($val);
            }
            $i++;
        }
        return $return;
    }

	/**
	 * 对中文字符串进行切割
	 *
	 * @static
     * @param string $str
     * @param int $length
     * @return array
	 */
	function splitStr($str, $length = 4000) {
		$len = mb_strlen($str);
		$max = ceil($len/$length);
		$result = array();
		for ($i=0; $i<$max; $i++) {
			$result[$i] = mb_substr($str, $i*$length, $length);
		}
		return $result;
	}

}