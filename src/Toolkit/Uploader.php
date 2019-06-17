<?php declare(strict_types=1);

namespace Brisk\Toolkit;

use BriskRuntimeException\RuntimeException;

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
     * @param array $types
     * @return Uploader
     */
    function setAllowTypes(array $types)
    {
        $this->_types = $types;
        return $this;
    }

    /**
     * 取得可上传的文件类型
     *
     * @return array
     */
    function getAllowTypes()
    {
        return $this->_types;
    }

    /**
     * 设置/获取文件上传的最大大小
     *
     * @access public
     * @param int $size
     * @return Uploader
     */
    function setAllowMaxSize(int $size)
    {
        $this->_size = $size;
        return $this;
    }

    /**
     * 获取文件上传的最大大小
     *
     * @access public
     * @return int
     */
    function getAllowMaxSize()
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
    public function setSavePath(callable $callback)
    {
        $this->_path = $callback;
        return $this;
    }

    /**
     * 处理上传过程
     *
     * @access public
     * @param array $file
     * @return array
     * @throws RuntimeException
     */
    function uploading(array $file)
    {
        //检测上传错误
        if ($file['error'] > 0) {
            throw new RuntimeException(sprintf('上传处理异常，错误代码："%s".', $file['error']));
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
            throw new RuntimeException(sprintf('不支持的上传类型："%s".', $file['type']));
        } elseif ($file['size'] > $this->_size) {
            throw new RuntimeException(sprintf('仅允许上传不大于"%s"字节大小的文件.', $this->_size));
        } elseif (!$this->_path || !is_callable($this->_path)) {
            throw new RuntimeException('上传文件保存路径未设置.');
        }
        $path = call_user_func_array($this->_path, [$file]);
        if (!file_exists($this->_path) && !File::mkDir($this->_path)) {
            throw new RuntimeException(sprintf('无法创建目标目录："%s".', dirname($path)));
        }
        //格式化文件名
        if (move_uploaded_file($file['tmp_name'], $path)) {
            return $path;
        }
    	return false;
    }

}