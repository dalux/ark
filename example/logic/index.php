<?php

$select = Ark_Database_SQLBuilder::select()
    ->from('abc', array('*'))
    ->where('tid=?', '123');
echo $select;
