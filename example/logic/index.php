<?php

$select = Ark_Sql_Builder::select()
    ->from('abc', array('*'))
    ->where('tid=?', '123');
echo $select;
