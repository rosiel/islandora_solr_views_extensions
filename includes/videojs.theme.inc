<?php
/**
 * @file
 * Theme and preprocess functions for the Video.js module.
 */

/**
 * Preprocess function for videojs.tpl.php when using a playlist.
 */


/**
 * Preprocess function for videojs.tpl.php when displaying a view as a playlist.
 */
function template_preprocess_videojs_view(&$vars) {
  videojs_add();
  $vars['player_id'] = 'videojs-view-' . str_replace('_', '-', $vars['view']->name);
}