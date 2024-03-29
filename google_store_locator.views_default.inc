<?php
/**
 * @file
 * google_store_locator.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function google_store_locator_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'google_store_locator_json_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Location Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Location Export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'wkt';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'gsl_geofield';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'gsl_geofield';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'gsl_geofield';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'gsl_geofield';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'title';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'gsl_addressfield';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Store Name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Store Locator Address */
  $handler->display->display_options['fields']['gsl_addressfield']['id'] = 'gsl_addressfield';
  $handler->display->display_options['fields']['gsl_addressfield']['table'] = 'field_data_gsl_addressfield';
  $handler->display->display_options['fields']['gsl_addressfield']['field'] = 'gsl_addressfield';
  $handler->display->display_options['fields']['gsl_addressfield']['label'] = 'Street Address';
  $handler->display->display_options['fields']['gsl_addressfield']['alter']['text'] = '[gsl_addressfield-thoroughfare]';
  $handler->display->display_options['fields']['gsl_addressfield']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['gsl_addressfield']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Store Locator Geofield */
  $handler->display->display_options['fields']['gsl_geofield']['id'] = 'gsl_geofield';
  $handler->display->display_options['fields']['gsl_geofield']['table'] = 'field_data_gsl_geofield';
  $handler->display->display_options['fields']['gsl_geofield']['field'] = 'gsl_geofield';
  $handler->display->display_options['fields']['gsl_geofield']['label'] = 'Coordinates';
  $handler->display->display_options['fields']['gsl_geofield']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['gsl_geofield']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Feature Filter List */
  $handler->display->display_options['fields']['gsl_feature_filter_list']['id'] = 'gsl_feature_filter_list';
  $handler->display->display_options['fields']['gsl_feature_filter_list']['table'] = 'field_data_gsl_feature_filter_list';
  $handler->display->display_options['fields']['gsl_feature_filter_list']['field'] = 'gsl_feature_filter_list';
  $handler->display->display_options['fields']['gsl_feature_filter_list']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'store_location' => 'store_location',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'store-locator/json';
  $translatables['google_store_locator_json_export'] = array(
    t('Master'),
    t('Location Export'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Store Name'),
    t('Street Address'),
    t('[gsl_addressfield-thoroughfare]'),
    t('Coordinates'),
    t('Feature Filter List'),
    t('Page'),
  );
  $export['google_store_locator_json_export'] = $view;

  return $export;
}
