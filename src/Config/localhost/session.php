<?php

return array(
    'driver'=> 'Brisk\Session\FileSession',
    'expire_time'=> 1440,
    'save_path'=> \Brisk\Core\Loader::realPath('./runtime/session/'),
);