<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_ISSUE_DAO.'class.createIssuedao.inc';

class CreateIssueBAO
{
	private $_CreateIssueDAO;

	function __construct(){
		$this->_CreateIssueDAO = new CreateIssueDAO();
	}

	

	public function getIssueBody($id){

		$Result = new Result();
		$Result = $this->_CreateIssueDAO->getIssueBody($id);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CreateIssueDAO.getNoticeBody()");

		return $Result;
	}

	public function CreateIssue($CreateIssue){
		$Result = new Result();
		$Result = $this->_CreateIssueDAO->CreateIssue($CreateIssue);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HousingDAO.createHousing()");		
		return $Result;
	}

	public function getAllIssue(){
		$Result = new Result();
		$Result = $this->_CreateIssueDAO->getAllIssue();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CreateIssueDAO.getAllNotice()");		
		return $Result;
	}



	public function updateCreateIssue($CreateIssue){

		$Result = new Result();
		$Result = $this->_CreateIssueDAO->updateCreateIssue($CreateIssue);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CreateIssueDAO.updateCreateIssue()");

		return $Result;
	}

	public function deleteCreateIssue($CreateIssue){

		$Result = new Result();
		$Result = $this->_CreateIssueDAO->deleteCreateIssue($CreateIssue);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CreateIssueDAO.deleteCreateIssue()");

		return $Result;

	}
	public function readCreateIssue($CreateIssue){


		$Result = new Result();
		$Result = $this->_CreateIssueDAO->readCreateIssue($CreateIssue);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CreateIssueDAO.readCreateIssue()");

		return $Result;


	}
}