<?php
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.inc';
include_once MODULES_NOTICE_BAO.'class.viewNoticebao.inc';

$_ViewNoticeBAO = new ViewNoticeBAO();
$globalUser = '';
$globalUser = $_SESSION["globalUser"];
$Result = new Result();
?>

