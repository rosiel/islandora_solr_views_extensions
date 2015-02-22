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
    videojs_add();
    $pid = $values->PID;
    $object = islandora_object_load($pid);

    $vars = array(
      'items' => array(),
    );

    if ($object['PROXY_MP4']) {
      $source_url = $object['PROXY_MP4']->url;

      // Add RTMP source
      $source_url_rtmp = str_replace('http', 'rtmp', $source_url);
      $vars['items'][] = array(
        'uri' => $source_url_rtmp,
        'filemime' => 'rtmp/mp4',
      );
      // Add Apple HLS source
      $source_url_hls = $source_url . '/playlist.m3u8';
      $vars['items'][] = array(
        'uri' => $source_url_hls,
        'filemime' => 'video/mp4',
      );
      // Add MPEG-DASH (not sure if affects anything?)
      /*
      $source_url_dash = $source_url . '/manifest.mpd';
      $vars['items'][] = array(
        'uri' => $source_url_dash,
        'filemime' => 'video/mp4',
      );
      */
      // Add Silverlight Microsoft Smooth Streaming source (?not sure if works?)
      $source_url_mss = $source_url . '/Manifest';
      $vars['items'][] = array(
        'uri' => $source_url_mss,
        'filemime' => 'application/x-silverlight-2',
      );
    }
    if ($object['OBJ']) {
      if ($object['OBJ']->mimetype == 'video/mpeg' || $object['OBJ']->mimetype == 'video/mp4') {
        $source_url = '/islandora/object/' . $object->id . '/datastream/OBJ';
        $mime = $object['OBJ']->mimetype;
        $vars['items'][] = array(
          'uri' => $source_url,
          'filemime' => 'video/mp4',
        );
      }
    }
    if ($object['TN']) {
      $poster_url = '/islandora/object/' . $object->id . '/datastream/TN/view';
      $poster_mime = $object['TN']->mimetype;
    }

    if (isset($poster_url)) {
      $vars['items'][] = array(
        'uri' => $poster_url,
        'filemime' => $poster_mime,
      );
    }
    $vars['player_id'] = 'videojs-'. str_replace(':', '_', $pid);
    $vars['posterimage_style'] = NULL;
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
