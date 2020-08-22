<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_NOTICE_BAO.'class.searchNoticebao.inc';


$_SearchNoticeBAO = new SearchNoticeBAO();

$_DB = DBUtil::getInstance();

if(isset($_POST['search']))
{


	if(isset($_POST['selectedField']))
	{	   
		$SearchField = $_POST['selectedField'];
	}

	if(isset($_POST['txtSearch']))
	{	   
		$SearchText = $_DB->secureInput($_POST['txtSearch']);

		$ResultSearch = $_SearchNoticeBAO->getNotice($SearchField,$SearchText);		
	}	
		
}


?>