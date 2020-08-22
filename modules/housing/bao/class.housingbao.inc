<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_HOUSING_DAO.'class.housingdao.inc';

/*
	Housing Business Object 
*/
Class HousingBAO{

	private $_DB;
	private $_HousingDAO;

	function __construct(){

		$this->_HousingDAO = new HousingDAO();

	}

	//get all Housing value
	public function getAllHousing(){

		$Result = new Result();	
		$Result = $this->_HousingDAO->getAllHousing();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HousingDAO.getAllHousing()");		

		return $Result;
	}


	public function getAllHousingById($Id){

		$Result = new Result();	
		$Result = $this->_HousingDAO->getAllHousingById($Id);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HousingDAO.getAllHousing()");		

		return $Result;
	}
	

	

	//create Housing funtion with the Housing object
	public function createHousing($Housing){

		$Result = new Result();	
		$Result = $this->_HousingDAO->createHousing($Housing);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HousingDAO.createHousing()");		

		return $Result;

	
	}
	
	public function getNameFromTypeID($Housing){


		$Result = new Result();	
		$Result = $this->_HousingDAO->getNameFromTypeID($Housing);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in _HousingDAO.getNameFromTypeID()");	//getNameFromTypeID edit	

		return $Result;


	}


	public function getNameFromID($id){


		$Result = new Result();	
		$Result = $this->_HousingDAO->getNameFromID($id);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in _HousingDAO.getNameFromTypeID()");	//getNameFromTypeID edit	

		return $Result;


	}


	

	//read for edit an Housing  object based on its id form Housing object
	public function readHousing($Housing){


		$Result = new Result();	
		$Result = $this->_HousingDAO->readHousing($Housing);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HousingDAO.readHousing()");		

		return $Result;


	}

	

	//update an Housing object based on its current information
	public function updateHousing($Housing){

		$Result = new Result();	
		$Result = $this->_HousingDAO->updateHousing($Housing);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HousingDAO.updateHousing()");		

		return $Result;
	}

	//delete an existing Housing
	public function deleteHousing($Housing){

		$Result = new Result();	
		$Result = $this->_HousingDAO->deleteHousing($Housing);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in HousingDAO.deleteHousing()");		

		return $Result;

	}

}

?>