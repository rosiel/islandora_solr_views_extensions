<?php

/**
 * @file
 * Views base handler for images.
 */

class IslandoraEthnographyHandlerImageDerivative extends views_handler_field {
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

    if ($object['JPG']) {
      return ("/islandora/object/$pid/datastream/JPG");
    }
    elseif ($object['MEDIUM_SIZE']) {
      return ("/islandora/object/$pid/datastream/MEDIUM_SIZE");
    }


    return '';
  }
}
