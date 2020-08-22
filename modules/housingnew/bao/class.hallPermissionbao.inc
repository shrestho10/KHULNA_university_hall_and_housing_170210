<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_NEWHOUSING_DAO.'class.hallPermissiondao.inc';

class HallPermissionBAO
{
	private $_HallPermissionDAO;

	function __construct(){
		$this->_HallPermissionDAO = new HallPermissionDAO();
	}


	public function HallPermission($HallPermission){
		$Result = new Result();
		$Result = $this->_HallPermissionDAO->HallPermission($HallPermission);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HousingDAO.createHousing()");		
		return $Result;
	}



	public function getAllHallPermission($h){
		$Result = new Result();
		$Result = $this->_HallPermissionDAO->getAllHallPermission($h);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HallPermissionDAO.getAllNotice()");		
		return $Result;
	}



	public function updateHallPermission($HallPermission){

		$Result = new Result();
		$Result = $this->_HallPermissionDAO->updateHallPermission($HallPermission);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HallPermissionDAO.updateHallPermission()");

		return $Result;
	}

	public function deleteHallPermission($HallPermission){

		$Result = new Result();
		$Result = $this->_HallPermissionDAO->deleteHallPermission($HallPermission);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HallPermissionDAO.deleteHallPermission()");

		return $Result;

	}
	public function readHallPermission($HallPermission){


		$Result = new Result();
		$Result = $this->_HallPermissionDAO->readHallPermission($HallPermission);

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HallPermissionDAO.readHallPermission()");

		return $Result;


	}

}