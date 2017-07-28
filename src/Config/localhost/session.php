<?php

return array(
    'driver'=> '\Ark\Assembly\Session\File',
    'expire_time'=> 1440,
    'save_path'=> \Ark\Core\Loader::realPath('./runtime/session/'),
);