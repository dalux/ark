<?php declare(strict_types=1);

namespace Brisk;

use Brisk\Exception\RuntimeException;

class Toolkit
{

    /**
     * Get array variable string
     *
     * @param mixed $params
     * @return string
     */
    public static function sprintr($params)
    {
        ob_start();
        print_r($params);
        return preg_replace('/\\]\\=\\>\\n(\\s+)/m', '] => ', ob_get_clean());
    }

    /**
     * Formatted print variable
     *
     * @param mixed $params
     * @return void
     */
    public static function printr(...$params)
    {
        foreach ($params as $val) {
            $result = self::sprintr($val);
            echo sprintf('<pre>%s</pre>', htmlspecialchars($result));
        }
    }

    /**
     * Get array variable string
     *
     * @param mixed $params
     * @return string
     */
    public static function svardump($params)
    {
        ob_start();
        var_dump($params);
        return preg_replace('/\\]\\=\\>\\n(\\s+)/m', '] => ', ob_get_clean());
    }

    /**
     * Formatted print variable
     *
     * @param mixed $params
     * @return void
     */
    public static function vardump(...$params)
    {
        foreach ($params as $val) {
            $result = self::svardump($val);
            echo sprintf('<pre>%s</pre>', htmlspecialchars($result));
        }
    }

    /**
     * Recursively create a directory
     *
     * @param string dir
     * @return bool
     */
    public static function mkDir(string $dir, int $mode = 0755)
    {
		$dir = trim($dir);
        if (!$dir = trim($dir)) {
            return false;
        }
        $dirs = [$dir];
        while (!file_exists($dir)) {
            $dir = dirname($dir);
            $dirs[] = $dir;
        }
        if (count($dirs)>1) {
            $dirs = array_reverse($dirs);
            foreach ($dirs as $k=> $v) {
                $v = rtrim($v, DIRECTORY_SEPARATOR);
                if (!file_exists($v) && !mkdir($v, $mode)) {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * Recursively copy a directory
     *
     * @param string $src
     * @param string $dst
     * @return void
     */
    public static function copyDir(string $src, string $dst)
    {
        $handle = opendir($src);
        self::mkDir($dst);
        while (true) {
			$file = readdir($handle);
			if ($file == false) {
				break;
			}
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
     * Recursively remove a directory
     *
     * @param string $dir_name
     * @return bool
     */
	public static function removeDir(string $dir_name)
	{
		if (is_dir($dir_name)) {
			$handle = opendir($dir_name);
			while(true) {
				$file = readdir($handle);
				if ($file == false) {
					break;
				}
				if (!in_array($file, ['.', '..'])) {
					$dir = $dir_name. '/' . $file;
					if (is_dir($dir)) {
						self::removeDir($dir);
					} else {
						unlink($dir);
					}
				}
			}
			closedir($handle);
			return rmdir($dir_name);
		}
		return true;
    }

    /**
     * 数据校验器
     *
     * @param array $data
     * @param array $rule
     */
    public static function validate(array $data, array $rule)
    {
        foreach ($rule as $field=> $item) {
            $value = $data[$field];
            foreach ($item as $k=> $v) {
                //必填项校验
                if ($k == 'required' && $v) {
                    if (is_string($v)) {
                        $special = [];
                        foreach ($rule as $_k=> $_v) {
                            if ($_v['required'] === $v) {
                                $special[$_k] = $_v;
                            }
                        }
                        $pass = false;
                        foreach ($special as $_k=> $_v) {
                            $_value = $data[$_k];
                            if ($_value || is_integer($_value)) {
                                $pass = true;
                            }
                        }
                        if (!$pass) {
                            throw new RuntimeException(Language::format('tool.validator_field_missing', $field));
                        }
                    } elseif (is_null($value)
                            || is_string($value) && trim($value) == ''
                            || is_array($value) && count($value) == 0) {
                        throw new RuntimeException(Language::format('tool.validator_field_missing', $field));
                    }
                }
                //以下校验在值不为空时进行
                if (!is_null($value)) {
                    //类型校验
                    if ($k == 'type') {
                        $type = strtolower(gettype($value));
                        $v = strtolower($v);
                        $number = ['double', 'float', 'real', 'integer', 'int'];
                        if (in_array($type, $number)
                                || $type == 'string' && $v == 'number' && is_numeric($value)) {
                            $type = 'number';
                        } elseif ($type == 'resource') {
                            $type = 'object';
                        }
                        if ($v != $type) {
                            throw new RuntimeException(Language::format('tool.validator_field_errtype', $field, $v, $type));
                        }
                    }
                    //范围校验
                    if ($k == 'range' && is_array($v)) {
                        if (!in_array($value, $v)) {
                            throw new RuntimeException(Language::format('tool.validator_field_outrange', $field));
                        }
                    }
                    //最小值校验
                    if ($k == 'min_value' && $value < $v) {
                        throw new RuntimeException(Language::format('tool.validator_filed_lessthan', $field, $v));
                    }
                    //最大值校验
                    if ($k == 'max_value' && $value > $v) {
                        throw new RuntimeException(Language::format('tool.validator_filed_morethan', $field, $v));
                    }
                    //最小长度校验
                    if ($k == 'min_length' && is_string($value) && strlen($value) < $v) {
                        throw new RuntimeException(Language::format('tool.validator_filed_minlength', $field, $v, strlen($value)));
                    }
                    //最大长度校验
                    if ($k == 'max_length' && is_string($value) && strlen($value) > $v) {
                        throw new RuntimeException(Language::format('tool.validator_filed_maxlength', $field, $v, strlen($value)));
                    }
                    //是否相等校验
                    if ($k == 'equal') {
                        if (is_string($value) && $value != $v) {
                            throw new RuntimeException(Language::format('tool.validator_filed_noequal', $field, $v, $value));
                        } elseif (is_object($value) && !$value instanceof $v) {
                            throw new RuntimeException(Language::format('tool.validator_filed_errobject', $field, get_class($v)));
                        }
                    }
                    //是否匹配规则
                    if ($k == 'match' && !preg_match($v, $value)) {
                        throw new RuntimeException(Language::format('tool.validator_filed_nomatch', $field, $v));
                    }
                }
            }
        }
    }

    /**
     * 判断是否是手机号码
     *
     * @access public
     * @static
     * @param string $mobile
     * @return bool
     */
    static function isMobile(string $mobile)
    {
        if (!is_numeric($mobile)) return false;
        return preg_match('#^13[\d]{9}$|^14[5,7]{1}\d{8}$|^15[\d]{9}$|^166[\d]{8}$|^17[\d]{9}$|^18[\d]{9}$|^19[8,9]{1}\d{8}$|^1980000[\d]{4}$#', $mobile) ? true : false;
    }

}