<?php
/**
 * @file
 * Views hook implementations for Islandora Solr Views Extensions.
 */

/**
 * Implements hook_views_data_alter().
 */
function islandora_solr_views_extensions_views_data_alter(&$data) {
  $data['islandora_solr']['audio_datastream_player'] = array(
    'title' => 'Audio Datastream Player',
    'help' => 'Displays a player for an audio datastream in the object.',
    'field' => array(
      'handler' => 'IslandoraEthnographyHandlerAudioPlayer',
    ),
  );
}
