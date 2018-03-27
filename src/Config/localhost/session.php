<?php

return array(
    'driver'=> 'Ark_Session_File',
    'expire_time'=> 1440,
    'save_path'=> Ark_Loader::realPath('./runtime/session/'),
);