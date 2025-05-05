<?php

// register Autoloader
define('PROJECT_DIR', realpath(__DIR__.'/..'));
require_once PROJECT_DIR.'/Lib/Autoloader.php';

new Autoloader(PROJECT_DIR);

/**
 * Main function
 */
function main(array $args) {

}

return main($argv);
