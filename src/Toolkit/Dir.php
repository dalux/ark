<?php declare(strict_types=1);

namespace Brisk\Toolkit;

class Dir
{

    /**
     * 递归创建目录
     *
     * @access public
     * @param string $dir
     * @param int $mode
     * @return bool
     */
    public static function create(string $dir, int $mode = 0755)
    {
        if ($dir = trim($dir)) {
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
        return false;
    }

    /**
     * 递归拷贝目录
     *
     * @access public
     * @param string $src
     * @param string $dst
     * @return bool
     */
    public static function copy(string $src, string $dst)
    {
        if (is_dir($src)) {
            $handle = opendir($src);
            self::create($dst);
            $sep = DIRECTORY_SEPARATOR;
            while (true) {
                $file = readdir($handle);
                if ($file == false) {
                    break;
                }
                if (($file != '.') && ($file != '..')) {
                    if (is_dir($src. $sep. $file)) {
                        self::copy($src. $sep. $file, $dst. $sep. $file);
                    } else {
                        copy($src. $sep. $file, $dst. $sep. $file);
                    }
                }
            }
            closedir($handle);
            return true;
        }
        return false;
    }

    /**
     * 递归删除目录
     *
     * @access public
     * @param string $dir_name
     * @return bool
     */
	public static function remove(string $dir_name)
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
						self::remove($dir);
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

}