<?php
// $Id$ 
function closure_compiler_settings() {
	$form['closure_compiler_service'] = array (
		'#type' => 'radios',
		'#title' => t('Google Closure Compiler Service'),
		'#default_value' => variable_get('closure_compiler_service', 0),
		'#options' => array (
			t('Disabled'),
			t('Enabled')
		),
		'#description' => t("Enables the use of Google Closure Compiler Service."),

		
	);
	$form['closure_compiler_api'] = array (
		'#type' => 'fieldset',
		'#title' => t('API Settings'),
		
	);
	$form['closure_compiler_api']['closure_compiler_process_limit'] = array (
		'#type' => 'textfield',
		'#title' => t('Process Limit'),
		'#default_value' => variable_get('closure_compiler_process_limit', 0),
		'#description' => t("Limit the number of javascript files that will be processed during a single cron run. 0 is unlimited.")
	);
	$form['closure_compiler_api']['closure_compiler_compilation_level'] = array (
		'#type' => 'radios',
		'#title' => t('Compilation Level'),
		'#default_value' => variable_get('closure_compiler_compilation_level', 1),
		'#options' => array (
			t('Whitespace only'),
			t('Simple optimizations'),
			t('Advanced optimizations'),
		),
		'#description' => t("The degree of compression and optimization to apply to your JavaScript. Check out the !link for more information. If unsure, keep the default setting. A change to this setting may require a cache clear to fully go into effect.",array('!link' => l('api reference page', 'http://code.google.com/closure/compiler/docs/api-ref.html'))),		
	);
	$form['closure_compiler_api']['closure_compiler_process_method'] = array (
		'#type' => 'radios',
		'#title' => t('Preferred Processing Method'),
		'#default_value' => variable_get('closure_compiler_process_method', 0),
		'#options' => array (
			t('Send JavaScript file contents to the API'),
			t('Send JavaScript file paths to the API (Requires your site to be public)'),
		),
		'#description' => t("First setting reads the cached JavaScript files under !filesyspath and sends the javascript code directly to the service to be compiled. Second setting sends the URI of the JavaScript file for its contents to be retrieved and compiled by the service. Your site's URLs must be public (not an internal development domain etc.) for this method to work. IMPORTANT NOTE: If your JavaScript payload size is bigger than 200000 bytes, the modules uses the second method regardless of this setting as it is the only mode possible in that case (API limitation).",array('!filesyspath' => file_directory_path())),		
	);
	// Warn the user if js aggregation is not enabled
	if (!variable_get('preprocess_js', 0)) {
		$form['closure_compiler_service']['#disabled'] = TRUE;
		drupal_set_message(t('Javascript aggregation has to be enabled for this module to work. Please enable Optimize Javascript Files feature under !link', array (
			'!link' => l('performance settings', 'admin/settings/performance')
		)), 'error');
	}
	return system_settings_form($form);
}