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
  $data['islandora_solr']['video_MP4_stream_player'] = array(
    'title' => 'Streaming Video Datastream Player',
    'help' => 'Displays a player for a streaming video datastream in the object.',
    'field' => array(
      'handler' => 'IslandoraEthnographyHandlerVideoPlayer',
    ),
  );
  $data['islandora_solr']['image_jpg_derivative'] = array(
    'title' => 'Image : JPG derivative',
    'help' => 'Returns the path (e.g. "/islandora/object/pid/datastream/JPG" to the medium sized jpg derivative from basic and large images.',
    'field' => array(
      'handler' => 'IslandoraEthnographyHandlerImageDerivative',
    ),
  );
  // Include a dismax query parser filter (q).
  $data['islandora_solr']['query_edismax'] = array(
    'title' => t('Query Parser (eDisMax)'),
    'help' => t('Query Parser field to perform EDisMax keyword searches.'),
    'filter' => array(
      'handler' => 'islandora_sve_views_handler_filter_query_edismax',
    ),
  );

}
