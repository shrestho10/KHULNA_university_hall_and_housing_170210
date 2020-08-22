<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_NOTICE_DAO.'class.viewNoticedao.inc';

class ViewNoticeBAO
{
	private $_ViewNoticeDAO;

	function __construct(){
		$this->_ViewNoticeDAO = new ViewNoticeDAO();
	}

	
	public function getAllNotice(){

		$Result = new Result();
		$Result = $this->_ViewNoticeDAO->getAllNotice();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ViewNoticeDAO.getAllNotice()");

		return $Result;
	}

	public function getNoticeById($Id){

		$Result = new Result();
		$Result = $this->_ViewNoticeDAO->getNoticeById($Id);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ViewNoticeDAO.getNoticeById()");

		return $Result;
	}

	
   

	
}