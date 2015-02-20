<?php

/**
 * @file
 * Views base handler for videos player.
 */

class IslandoraEthnographyHandlerVideoPlayer extends views_handler_field {
  /**
   * Inherits.
   *
   * @param object $values
   *   An object containing the values of the query thus far.
   *
   * @return string
   *   The rendered markup string.
   */
  public function render($values) {
    $pid = $values->PID;
    $object = islandora_object_load($pid);

    if (FALSE && $object['PROXY_MP4']) {
      $source_url = $object['PROXY_MP4']->url;
      $source_url = str_replace('http', 'rtmp', $source_url);
      $mime = $object['PROXY_MP4']->mimetype;
    }
    elseif ($object['OBJ']) {
      if ($object['OBJ']->mimetype == 'video/mpeg' || $object['OBJ']->mimetype == 'video/mp4') {
        $source_url = '/islandora/object/' . $object->id . '/datastream/OBJ/view.mp4';
        $mime = $object['OBJ']->mimetype;
      }
    }
    if ($object['TN']) {
      $poster_url = '/islandora/object/' . $object->id . '/datastream/TN/view';
      $poster_mime = $object['TN']->mimetype;
    }
    $vars = array(
      'items' => array(),
    );
    if (isset($source_url)) {
      $vars['items'][] = array(
        'uri' => $source_url,
        'filemime' => $mime,
      );
    }
    if (isset($poster_url)) {
      $vars['items'][] = array(
        'uri' => $poster_url,
        'filemime' => $poster_mime,
      );
    }
    $vars['player_id'] = 'videojs-'. str_replace(':', '_', $pid);
    $vars['posterimage_style'] = 'thumbnail';
    $vars['attributes'] = array(
      'width' => 640,
      'height' => 360,
      'loop' => FALSE,
      'autoplay' => FALSE,
      'preload' => 'none',
      'hidecontrols' => FALSE,
    );

    return theme('videojs', $vars);
  }
}
