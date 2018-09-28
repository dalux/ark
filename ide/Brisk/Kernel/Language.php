<?php

namespace Brisk\Kernel;


class Language
{

    static private $_language = 'en_us';


    static private $_package = array('en_us' => array('core.framework_not_ready' => 'Framework not initialized', 'core.invalid_controller_path' => 'Invalid controller directory', 'core.invalid_configuration' => 'No valid configuration information found', 'core.invalid_config_format' => 'Configuration file [%s] must return array format data', 'core.object_not_found' => 'Unable to find a member', 'core.invalid_autoloader' => 'The auto loader cannot be called', 'core.format_path_failed' => 'Unable to format specified path[%s]', 'core.class_path_notfound' => 'The file corresponding to classname[%s] does not exist', 'core.invlid_custom_member' => 'Custom member[%s] must return a valid object', 'core.invlid_custom_method' => 'Custom methods[%s] must be callable', 'core.custom_method_notfound' => 'Cannot find custom method[%s]', 'core.config_not_found' => 'Unable to find a configuration item[%s]', 'http.request_not_ready' => 'Http request data not ready', 'http.method_not_found' => 'The called method[%s] does not exist', 'http.property_not_found' => 'The called attribute object[%s] does not exist', 'event.struct_check_failed' => 'Event listener[%s] return value structure check failure[%s]', 'event.data_must_array' => 'Event listener[%s] must return an array', 'event.data_key_must_equal' => 'Event listener[%s] array returns incomplete key values', 'router.uri_parse_failed' => 'Routing parsing result anomaly[%s]', 'router.invalid_controller_name' => 'No valid controller name', 'router.class_not_found' => 'The requested controller classname[%s] does not exist', 'router.action_not_found' => 'Controller behavior[%s] does not exist', 'router.controller_not_found' => 'The requested controller[%s] does not exist', 'router.invalid_driver_name' => 'No valid routing drive name', 'router.driver_not_found' => 'Routing driver class[%s] does not exist', 'router.driver_implement_error' => 'The routing driver class[%s] must implement the interface[%s]', 'router.call_func_failed' => 'Unable to call custom Uri rewriting function[%s]', 'router.uri_must_string' => 'The rewritten Uri must be a string', 'router.controller_is_protected' => 'Access to a closed controller[%s]', 'router.configuration_missing' => 'Routing configuration item [%s] missing', 'tbox.invalid_db_connstr' => 'Invalid database connection string[%s]', 'tbox.invalid_create_path' => 'No directory path to create specified', 'tbox.invalid_db_connection' => 'The database connection object must implement the [\\\\Brisk\\\\Contract\\\\IDatabase] interface', 'tbox.invalid_cache_object' => 'The cache object must implement the [\\\\Brisk\\\\Contract\\\\ICache] interface', 'tbox.parse_string_failed' => 'Unable to parse string[%s]:[%s]', 'tbox.no_db_instance' => 'Database connection object instance not set', 'cache.driver_not_found' => 'Cache drive class[%s] does not exist', 'cache.driver_implement_error' => 'Cache drive class[%s] must inherit from the class[%s]', 'cache.dir_create_failed' => 'Unable to create cache file to save directory[%s]', 'cache.dir_permission_error' => 'The cache directory[%s] has insufficient access to read and write', 'cache.extension_load_failed' => 'Load extension[%s] failure', 'cache.cacher_create_failed' => 'Cache object[%s] failed to create', 'cache.path_mustbe_notnull' => 'The return value of the formatted path function cannot be null', 'proxy.target_not_callable' => 'The specified object or method cannot be invoked', 'proxy.invalid_cacher_object' => 'Proxy cache must implement interface', 'db.parse_sql_failed' => 'SQL statement parsing failure', 'db.connect_failed' => 'Database connection failure', 'db.driver_not_found' => 'Database driver class[%s] does not exist', 'db.driver_implement_error' => 'The database driver class[%s] must realize the interface between[%s] and [%s].', 'db.extension_load_failed' => 'Load extension[%s] failure', 'db.querier_type_missing' => 'Missing database type parameters', 'db.invalid_conn_string' => 'Invalid database connection string[%s]', 'querier.type_not_supported' => 'unsupported querier type [%s]', 'view.invalid_driver_name' => 'No valid view drive name', 'view.driver_not_found' => 'The view drive class[%s] does not exist', 'view.driver_implement_error' => 'The view driver class[%s] must implement the interface[%s]', 'view.template_not_found' => 'The template file [%s] does not exist', 'view.include_file_not_found' => 'The file[%s] to include does not exist'));


    /**
     * Add a Language Pack
     *
     * @param string $language
     * @param array $package
     * @return null
     */
    public static function addPackage($language, array $package = array()) {}

    /**
     * Add a Language pack file
     *
     * @param string $language
     * @param string $path
     * @return null
     */
    public static function addPackageFile($language, $path) {}

    /**
     * Gets the language pack for the specified language
     *
     * @param string $language
     * @return null
     */
    public static function getPackage($language = '') {}

    /**
     * Setting the current system language
     *
     * @param string $language
     * @return null
     */
    public static function setLanguage($language) {}

    /**
     * Parsing language Tags
     *
     * @param string $label
     * @param array $params
     * @return string
     */
    public static function get($label, array $params = array()) {}

}
