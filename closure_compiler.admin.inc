<?php
// $Id$ 
function closure_compiler_settings() {
	$form['closure_compiler_service'] = array (
		'#type' => 'radios',
		'#title' => t('Google Closure Compiler Service'),
		'#default_value' => variable_get('closure_compiler_service', FALSE),
		'#options' => array (
			t('Disabled'),
			t('Enabled')
		),
		'#description' => t("Enables the use of Google Closure Compiler Service."),		
	);
	$form['closure_compiler_process_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Process Limit'),
    '#default_value' => variable_get('closure_compiler_process_limit', 0),
    '#description' => t("Limit the number of javascript files that will be processed during a single cron run. 0 is unlimited.")
  );
	// Warn the user if js aggregation is not enabled
	if (!variable_get('preprocess_js', 0)) {
		$form['closure_compiler_service']['#disabled'] = TRUE;
		drupal_set_message(t('Javascript aggregation has to be enabled for this module to work. Please enable Optimize Javascript Files feature under !link', array('!link'=> l('performance settings', 'admin/settings/performance'))), 'error');
	}
	return system_settings_form($form);
}