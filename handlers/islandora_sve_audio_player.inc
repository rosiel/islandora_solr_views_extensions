<?php

/**
 * @file
 * Views base handler for audio player.
 */

class IslandoraEthnographyHandlerAudioPlayer extends views_handler_field {
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

    if ($object['PROXY_MP3']) {
      $audio_link = '/islandora/object/' . $object->id . '/datastream/PROXY_MP3';
      $mime = $object['PROXY_MP3']->mimetype;
    }
    elseif ($object['OBJ']) {
      $audio_link = '/islandora/object/' . $object->id . '/datastream/OBJ';
      $mime = $object['OBJ']->mimetype;
    }
    if (isset($mime) && in_array($mime, array('audio/mp3', 'audio/mpeg'))) {
      $player = '<audio controls preload="none"><source src="' . $audio_link . '" type="' . $mime . '" /> </audio>';
      return $player;
    }
    return NULL;
  }
}
