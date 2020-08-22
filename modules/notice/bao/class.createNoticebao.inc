<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_NOTICE_DAO.'class.createNoticedao.inc';

class CreateNoticeBAO
{
	private $_CreateNoticeDAO;

	function __construct(){
		$this->_CreateNoticeDAO = new CreateNoticeDAO();
	}

	

	public function getNoticeBody($subject){

		$Result = new Result();
		$Result = $this->_CreateNoticeDAO->getNoticeBody($subject);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CreateNoticeDAO.getNoticeBody()");

		return $Result;
	}

	public function createNotice($CreateNotice){
		$Result = new Result();
		$Result = $this->_CreateNoticeDAO->createNotice($CreateNotice);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HousingDAO.createHousing()");		
		return $Result;
	}

	public function getAllNotice(){
		$Result = new Result();
		$Result = $this->_CreateNoticeDAO->getAllNotice();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CreateNoticeDAO.getAllNotice()");		
		return $Result;
	}



	public function updateCreateNotice($CreateNotice){

		$Result = new Result();
		$Result = $this->_CreateNoticeDAO->updateCreateNotice($CreateNotice);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CreateNoticeDAO.updateCreateNotice()");

		return $Result;
	}

	public function deleteCreateNotice($CreateNotice){

		$Result = new Result();
		$Result = $this->_CreateNoticeDAO->deleteCreateNotice($CreateNotice);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CreateNoticeDAO.deleteCreateNotice()");

		return $Result;

	}
	public function readCreateNotice($CreateNotice){


		$Result = new Result();
		$Result = $this->_CreateNoticeDAO->readCreateNotice($CreateNotice);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CreateNoticeDAO.readCreateNotice()");

		return $Result;


	}
}