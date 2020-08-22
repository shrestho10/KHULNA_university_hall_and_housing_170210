<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_NOTICE_DAO.'class.searchNoticedao.inc';

/*
	Housing Details Business Object 
*/
Class SearchNoticeBAO{

	private $_DB;
	private $_SearchNoticeDAO;

	function __construct(){

		$this->_SearchNoticeDAO = new SearchNoticeDAO();
	}

	public function getNotice($SearchField,$SearchText){

		$Result = new Result();
		$Result = $this->_SearchNoticeDAO->getNotice($SearchField,$SearchText);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in SearchNoticeDAO.getNotice($SearchField,$SearchText)");

		return $Result;
	}

	//search an user object
	
}

?>