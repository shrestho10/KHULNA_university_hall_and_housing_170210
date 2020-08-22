<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once UTILITY.'class.util.inc';
include_once MODULES_HOUSING_DAO.'class.housingdao.inc';

Class HousingDetailsDAO{

	private $_DB;
	private $_HousingProvost;
	private $_HousingAssistantProvost;

	function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_HousingProvost= new HousingProvost();
		$this->_HousingAssistantProvost= new HousingAssistantProvost();

	}

	// get all the Housing from the database using the database query
	

	public function getAllProvost($id)
	{
		$HousingProvostList = array();
		
		$this->_DB->doQuery("SELECT * FROM hms_provost WHERE house_id = '".$id."'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_HousingProvost = new HousingProvost();

		    $this->_HousingProvost->setID ( $row['provost_id']);
		    $this->_HousingProvost->setUserID ( $row['UniversityID']);
		    $this->_HousingProvost->setHousingId( $row['house_id'] );
		    $this->_HousingProvost->setProvost( $row['provost_name'] );
		    
		    


		    $HousingProvostList[]=$this->_HousingProvost;
   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($HousingProvostList);

		return $Result;
	}
	public function getAllAssistantProvost($id)
	{
		$HousingAssistantProvostList = array();
		
		$this->_DB->doQuery("SELECT * FROM hms_assistant_provost WHERE house_id = '".$id."'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_HousingAssistantProvost = new HousingAssistantProvost();

		    $this->_HousingAssistantProvost->setID ( $row['assistant_provost_id']);
		    $this->_HousingAssistantProvost->setHousingId( $row['house_id'] );
		    $this->_HousingAssistantProvost->setAssProvost( $row['name'] );
		    
		    


		    $HousingAssistantProvostList[]=$this->_HousingAssistantProvost;
   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($HousingAssistantProvostList);

		return $Result;
	}

	public function getAllEmployee($id)
	{
		$HousingEmployeeList = array();
		
		$this->_DB->doQuery("SELECT * FROM hms_employee WHERE house_id = '".$id."'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_HousingEmployee = new HousingEmployee();

		    $this->_HousingEmployee->setID ( $row['employee_id']);

		    $this->_HousingEmployee->setHousingId( $row['house_id'] );
		    $this->_HousingEmployee->setOfficer( $row['name'] );
		    
		    


		    $HousingEmployeeList[]=$this->_HousingEmployee;
   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($HousingEmployeeList);

		return $Result;
	}

	public function getNameFromId($HousingId){

		$SQL = "SELECT * FROM hms_housing WHERE id='".$HousingId."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_Housing = new Housing();

		$this->_Housing->setID ( $row['id']);
		$this->_Housing->setName( $row['name'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Housing);

		return $Result;
	}
	


	//create Housing Details funtion with the Housing object
	public function createHousingProvost($HousingProvost){

		$Id=$HousingProvost->getID();
		$UserId=$HousingProvost->getUserId();
		$HousingId=$HousingProvost->getHousingId();
		$Provost=$HousingProvost->getProvost();
	
		$SQL = "INSERT INTO hms_provost (provost_id,house_id,provost_name,UniversityID) 
				VALUES('$Id','$HousingId','$Provost','$UserId')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	public function createHousingAssProvost($HousingAssProvost){

		$Id=$HousingAssProvost->getID();
		
		$HousingId=$HousingAssProvost->getHousingId();
		
		$AssProvost=$HousingAssProvost->getAssProvost();
		
		
	

		$SQL = "INSERT INTO hms_assistant_provost (assistant_provost_id,house_id,name) 
				VALUES('$Id','$HousingId','$AssProvost')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}
	public function createHousingEmployee($HousingEmployee){

		$Id=$HousingEmployee->getID();
		
		$HousingId=$HousingEmployee->getHousingId();
		$Officer=$HousingEmployee->getOfficer();
		
		
	

		$SQL = "INSERT INTO hms_employee (employee_id,house_id,name) 
				VALUES('$Id','$HousingId','$Officer')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}



	//delete an Housing Details based on its id of the database
	public function deleteHousingProvost($HousingProvost){


		$SQL = "DELETE from hms_provost where provost_id ='".$HousingProvost->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	public function deleteHousingAssistantProvost($HousingAssistantProvost){


		$SQL = "DELETE from hms_assistant_provost where assistant_provost_id ='".$HousingAssistantProvost->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	public function deleteHousingEmployee($HousingEmployee){


		$SQL = "DELETE from hms_employee where employee_id ='".$HousingEmployee->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}


	public function getHallIdFromId($Id){
		$List = array();

		$SQL = "SELECT * FROM hallpermission WHERE userid='".$Id."'";
		$SQL = $this->_DB->doQuery($SQL);

		$rows = $this->_DB->getAllRows();

		for ($i=0; $i < sizeof($rows); $i++) { 
			$row = $rows[$i];

		$this->_Housing = new Housing();

		
		$this->_Housing->setHallId( $row['hallid'] );
		$List[] = $this->_Housing;
		
		}
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($List);

		return $Result;
	}

}

?>