<?php declare(strict_types=1);

namespace Brisk\Toolkit;

class File
{

    /**
     * Recursively create a directory
     *
     * @param string $dir
     * @pram bool $mode
     * @return bool
     */
    public static function mkDir(string $dir, int $mode = 0755)
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
     * Recursively copy a directory
     *
     * @param string $src
     * @param string $dst
     * @return bool
     */
    public static function copyDir(string $src, string $dst)
    {
        if (is_dir($src)) {
            $handle = opendir($src);
            self::mkDir($dst);
            $sep = DIRECTORY_SEPARATOR;
            while (true) {
                $file = readdir($handle);
                if ($file == false) {
                    break;
                }
                if (($file != '.') && ($file != '..')) {
                    if (is_dir($src. $sep. $file)) {
                        self::copyDir($src. $sep. $file, $dst. $sep. $file);
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

}