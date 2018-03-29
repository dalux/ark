<?php

return array(
    'driver'=> 'Ark\Session\FileSession',
    'expire_time'=> 1440,
    'save_path'=> \Ark\Core\Loader::realPath('./runtime/session/'),
);