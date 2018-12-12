<?php

namespace Brisk\Kernel;

use Brisk\Http\Request;
use Brisk\Exception\RuntimeException;

class Server
{

    /**
     * Check if it is CLI mode
     *
     * @return bool
     */
	public static function isCli()
	{
		return php_sapi_name() == "cli";
	}

    /**
     * Get current Server domain name
     *
     * @param bool reduce
     * @return string
     */
    public static function getDomain($reduce = true)
    {
        $domain = strtolower($_SERVER['HTTP_HOST']);
		if ($domain != 'localhost' && !preg_match('/\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}/i', $domain)) {
			$pattern = '/^(.*?)\\.([^\\.]+?)\\.(dev|com|cn|net|com\\.cn|org|org\\.cn|cc|de|net\\.cn|co|tv|hk|me|info|name|biz|so|mobi|gov\\.cn|wang)?$/i';
			$matches = [];
			$matched = preg_match_all($pattern, $domain, $matches);
			if ($reduce && $matched > 0) {
				return sprintf('%s.%s', $matches[2][0], $matches[3][0]);
			}
		}
        return $domain;
    }

    /**
     * Get server sub-domain name
     *
     * @return string
     */
    public static function getSubDomain()
    {
        $domain = strtolower($_SERVER['HTTP_HOST']);
        $host = self::getDomain(true);
        $prefix = trim(str_replace($host, '', $domain), '.');
        return $prefix != '' ? $prefix : 'www';
    }

    /**
     * Init cli mode
     *
     * @return void
     */
    public static function initCli()
    {
		$data = $_GET;
		$argv = $_SERVER['argv'];
		array_shift($argv);
		$url_defined = false;
        foreach ($argv as $arg) {
			if (substr($arg, 0, 2) != '--') {
				continue;
			}
            $arg = ltrim($arg, '--');
			$key = substr($arg, 0, strpos($arg, '='));
			$val = substr($arg, (strpos($arg, '=') + 1));
			if ($key == 'url') {
				$info = parse_url($val);
				$_SERVER['HTTP_HOST'] = $info['host'];
				$_SERVER['REQUEST_URI'] = $info['path'];
				if ($info['query'] != '') {
					$_SERVER['REQUEST_URI'] = $info['path']. '?'. $info['query'];
				}
				$url_defined = true;
			} else {
				$data[$key] = $val;
			}
		}
		if (!$url_defined) {
			throw new RuntimeException(Language::get('core.cli_parameter_missing', 'url'));
		}
		Request::setData($data);
	}

}