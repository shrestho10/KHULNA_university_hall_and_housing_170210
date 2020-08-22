<?php
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.inc';
include_once MODULES_ISSUE_BAO.'class.viewIssuebao.inc';

$_ViewIssueBAO = new ViewIssueBAO();
$globalUser = '';
$globalUser = $_SESSION["globalUser"];
$Result = new Result();
?>

