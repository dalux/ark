<?php

namespace Brisk\Kernel;

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
    public static function mkDir($dir)
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
                if (!file_exists($v) && !mkdir($v, 0777)) {
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
    public static function copyDir($src, $dst)
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
	public static function removeDir($dir_name)
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
     * 从配置文件或文件夹中加载配置项
     *
     * @param string $domain
     * @param string $base_path
     * @param bool $from_dir
     * @return array
     */
    public static function getConfigByDomain($domain, $base_path, $from_dir = false)
    {
        if (!$from_dir) {
            $config_file = rtrim($base_path, DIRECTORY_SEPARATOR). DIRECTORY_SEPARATOR. $domain. '.php';
            if (!is_file($config_file)) {
                return [];
            }
            return (array)include($config_file);
        }
        $config_dir = rtrim($base_path, DIRECTORY_SEPARATOR). DIRECTORY_SEPARATOR. $domain;
        if (!is_dir($config_dir)) {
            return [];
        }
        $list_config_file = glob($config_dir. DIRECTORY_SEPARATOR. '*.php');
        $config = [];
        foreach ($list_config_file as $key=> $val) {
            $item = strtolower(preg_replace('/\.php$/', '', basename($val)));
            $config[$item] = include($val);
        }
        return $config;
    }

}