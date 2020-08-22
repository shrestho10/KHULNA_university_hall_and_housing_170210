<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_HOUSING_DAO.'class.housingSearchdao.inc';

/*
	Housing Details Business Object 
*/
Class HousingSearchBAO{

	private $_DB;
	private $_HousingSearchDAO;

	function __construct(){

		$this->_HousingSearchDAO = new HousingSearchDAO();
	}

	public function getHousingNameFromId($id)
	{
		$Result = new Result();	
		$Result = $this->_HousingSearchDAO->getHousingNameFromId($id);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HousingSearchDAO.getHousingNameFromId()");		

		return $Result;
	}

	//search an user object
	public function searchUser($SearchField,$SearchText){

		$Result = new Result();	
		$Result = $this->_HousingSearchDAO->searchUser($SearchField,$SearchText);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("No User found!!");		

		return $Result;
	}
}

?>