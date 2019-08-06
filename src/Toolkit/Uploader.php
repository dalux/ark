<?php declare(strict_types=1);

namespace Brisk\Toolkit;

use Brisk\Kernel\Language;
use Brisk\Exception\RuntimeException;

class Uploader
{

    /**
     * 允许上传类型
     *
     * @access private
     * @var array
     */
    private $_types = [
        'jpg', 'gif', 'png', 'mp3', 'm4a', 'mp4', 'zip', 'rar', 
        'xlsx', 'xls', 'doc', 'docx', 'csv', 'ppt', 'pdf', 'pptx', 'txt'
    ];

    /**
     * 上传类型mime映射
     *
     * @access private
     * @var array
     */
    private $_mime = [
        'image/gif'                                                                 => 'gif',
        'image/jpg'                                                                 => 'jpg',
        'image/jpeg'                                                                => 'jpg',
        'image/pjpeg'                                                               => 'jpg',
        'image/png'                                                                 => 'png',
        'image/bmp'                                                                 => 'bmp',
        'application/vnd.ms-powerpoint'                                             => 'ppt',
        'application/vnd.ms-excel'                                                  => 'xls',
        'application/vnd.ms-word'                                                   => 'doc',
        'application/x-zip-compressed'                                              => 'zip',
        'application/x-zip'                                                         => 'zip',
        'application/zip'                                                           => 'zip',
        'application/octet-stream'		                                            => 'rar',
        'file/xlsx'                                                                 => 'xlsx',
        'file/xls'                                                                  => 'xls',
        'file/csv'                                                                  => 'csv',
        'text/csv'                                                                  => 'csv',
        'file/docx'                                                                 => 'docx',
        'application/vnd.openxmlformats-officedocument.wordprocessingml.document'   => 'docx',
        'text/plain'                                                                => 'txt',
        'application/pdf'                                                           => 'pdf',
        'application/vnd.ms-powerpoint '                                            => 'ppt',
        'file/pptx'                                                                 => 'pptx',
        'application/vnd.openxmlformats-officedocument.presentationml.presentation' => 'pptx',
        'application/msword'                                                        => 'doc',
		'audio/mpeg'                                                                => 'mp3',
		'audio/mp3'						                                            => 'mp3',
        'audio/m4a'                                                                 => 'm4a',
        'audio/x-m4a'                                                               => 'm4a',
        'audio/mp4'                                                                 => 'm4a',
        'video/mp4'						                                            => 'mp4',
		'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet'         => 'xlsx',
    ];

    /**
     * 允许上传的最大大小，默认2MB
     *
     * @access private
     * @var integer
     */
    private $_size = 2097152;

    /**
     * 上传文件保存路径
     *
     * @access private
     * @var string
     */
    private $_path;

    /**
     * 设置可上传的文件类型
     *
     * @access public
     * @access public
     * @param array $types
     * @return Uploader
     */
    public function setLimitTypes(array $types)
    {
        $this->_types = $types;
        return $this;
    }

    /**
     * 取得可上传的文件类型
     *
     * @access public
     * @return array
     */
    public function getLimitTypes()
    {
        return $this->_types;
    }

    /**
     * 设置/获取文件上传的最大大小
     *
     * @access public
     * @access public
     * @param int $size
     * @return Uploader
     */
    public function setMaxBytes(int $size)
    {
        $this->_size = $size;
        return $this;
    }

    /**
     * 获取文件上传的最大大小
     *
     * @access public
     * @access public
     * @return int
     */
    public function getMaxBytes()
    {
        return $this->_size;
    }

    /**
     * 设置文件保存路径
     *
     * @access public
     * @param callable $callback
     * @return Uploader
     */
    public function setFilePath(callable $callback)
    {
        $this->_path = $callback;
        return $this;
    }

    /**
     * 处理上传过程
     *
     * @access public
     * @param array $file
     * @return string
     * @throws RuntimeException
     */
    public function upload(array $file)
    {
        //检测上传错误
        if ($file['error'] > 0) {
            throw new RuntimeException(Language::format('tool.upload_error_occurred', $file['error']));
        }
        //检测类型
        if ($file['tmp_name'] && $file['type'] == 'application/octet-stream') {
			$fileinfo = pathinfo($file['name']);
			if (in_array(strtolower($fileinfo['extension']), ['jpg', 'gif', 'png', 'bmp'])) {
				$fileinfo = getimagesize($file['tmp_name']);
				$file['type'] = $fileinfo['mime'];
			}
        }
        $type = $this->_mime[$file['type']];
        if (!in_array($type, $this->_types)) {
            throw new RuntimeException(Language::format('tool.upload_types_unsupport', $file['type']));
        } elseif ($file['size'] > $this->_size) {
            throw new RuntimeException(Language::format('tool.upload_bytes_oversize', $this->_size));
        } elseif (!$this->_path || !is_callable($this->_path)) {
            throw new RuntimeException(Language::format('tool.upload_filepath_error'));
        }
        $path = call_user_func_array($this->_path, [$file]);
        if (!file_exists($path) && !Dir::create(dirname($path))) {
            throw new RuntimeException(Language::format('tool.dir_create_failed', dirname($path)));
        }
        //格式化文件名
        if (move_uploaded_file($file['tmp_name'], $path)) {
            return $path;
        }
    	return '';
    }

}