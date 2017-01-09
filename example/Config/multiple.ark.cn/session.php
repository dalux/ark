<?php

return array(
    'driver'=> '\Ark\Session\Driver\File',
    'expire_time'=> 1440,
    'save_path'=> \Ark\Core\Loader::realPath('./runtime/session'),
);