<?php
/**
 * @file
 * Provides rules integration for interval module
 * @copyright Copyright(c) 2011 Lee Rowlands
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Lee Rowlands contact at rowlandsgroup dot com
 *
 */

/**
 * Implements hook_rules_action_info().
 */
function interval_rules_action_info() {
  $actions = array();

  $actions['interval_rules_apply_interval'] = array(
    'label' => t('Apply an interval to a datestamp'),
    'parameter' => array(
      'interval' => array(
        'type' => 'int',
        'label' => t('Interval')
      ),
      'period' => array(
        'type' => 'string',
        'label' => t('Interval Period')
      ),
      'datestamp' => array(
        'type' => 'int',
        'label' => t('Datestamp'),
      ),
    ),
    'provides' => array(
      'datestamp' => array(
        'type' => 'int',
        'label' => t('New Datestamp'),
        'description' => t('The new datestamp.'),
      ),
    ),
    'group' => t('Data'),
  );

  return $actions;
}

/**
 * Rules action callback.
 * Apply an interval to a date
 */
function interval_rules_apply_interval($interval, $period, $datestamp) {
  $date = new DateObject($datestamp, date_default_timezone(), 'U');
  $item = array(
    'interval' => $interval,
    'period' => $period
  );
  interval_apply_interval($date, $item);
  return array('datestamp' => $date->format('U'));
}
