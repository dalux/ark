<?php

namespace Ark\Com\Database;

class Expr
{
    
    /**
     * 表达式变量
     *
     * @access private
     * @var string
     */ 
    private $_expr;
    
    /**
     * 构造函数
     * 
     * @param string $expr
     */
    function __construct($expr = null)
    {
    	if (!is_null($expr)) $this->_expr = $expr;
    }
    
    /**
     * 设置表达式
     *
     * @access public
     * @param string $expr
     * @return Expr
     */    
    function set($expr)
    {
    	$this->_expr = $expr;
    	return $this;
    }
    
    /**
     * 通过魔术方法返回表达式
     *
     * @access public
     * @return string
     */
    function __toString() 
    {
        return $this->_expr;
    }
    
}