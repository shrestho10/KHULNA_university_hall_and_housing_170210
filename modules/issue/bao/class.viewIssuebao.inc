<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_ISSUE_DAO.'class.viewIssuedao.inc';

class ViewIssueBAO
{
	private $_ViewIssueDAO;

	function __construct(){
		$this->_ViewIssueDAO = new ViewIssueDAO();
	}

	
	public function getAllIssue(){

		$Result = new Result();
		$Result = $this->_ViewIssueDAO->getAllIssue();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ViewIssueDAO.getAllIssue()");

		return $Result;
	}

	public function getIssueById($Id){

		$Result = new Result();
		$Result = $this->_ViewIssueDAO->getIssueById($Id);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ViewIssueDAO.getIssueById()");

		return $Result;
	}

	
   

	
}