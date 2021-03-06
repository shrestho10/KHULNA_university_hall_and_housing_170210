<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once UTILITY.'class.util.inc';
include_once MODULES_HOUSING_DAO.'class.housingTypedao.inc';

Class HousingDAO{

	private $_DB;
	private $_Type;

	function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Type = new HousingType();

	}

	// get all the Housing from the database using the database query
	public function getAllHousing(){

		$HousingList = array();

		$this->_DB->doQuery("SELECT * FROM hms_housing");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Housing = new Housing();

		    $this->_Housing->setID ( $row['id']);
		    $this->_Housing->setName( $row['name'] );
		    $this->_Housing->setTypeId( $row['type_id'] );
		    $this->_Housing->setFloor( $row['no_of_floor'] );
		    $this->_Housing->setRoom( $row['no_of_room'] );
		    

		    $HousingList[]=$this->_Housing;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($HousingList);

		return $Result;
	}



	public function getAllHousingById($Id){

		$HousingList = array();

		$this->_DB->doQuery("SELECT * FROM hms_housing  amd  where id = '".$Id."' ");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Housing = new Housing();

		    $this->_Housing->setID ( $row['id']);
		    $this->_Housing->setName( $row['name'] );
		    $this->_Housing->setTypeId( $row['type_id'] );
		    $this->_Housing->setFloor( $row['no_of_floor'] );
		    $this->_Housing->setRoom( $row['no_of_room'] );
		    

		    $HousingList[]=$this->_Housing;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($HousingList);

		return $Result;
	}
	

	public function getNameFromTypeID($TypeID){

		$SQL = "SELECT * FROM hms_type WHERE id='".$TypeID."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_HousingType = new HousingType();

		$this->_HousingType->setID ( $row['id']);
		$this->_HousingType->setName( $row['name'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_HousingType);

		return $Result;
	}


	//create Housing funtion with the Housing object
	public function createHousing($Housing){

		$ID=$Housing->getID();
		$Name=$Housing->getName();
		$Type=$Housing->getTypeId();
		$Floor=$Housing->getFloor();
		$Room=$Housing->getRoom();
		
	

		$SQL = "INSERT INTO hms_housing (id,name,type_id,no_of_floor,no_of_room) 
				VALUES('$ID','$Name','$Type','$Floor','$Room')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	


	//read an Housing object based on its id form Housing object
	public function readHousing($Housing){
		
		
		$SQL = "SELECT * FROM hms_housing WHERE id='".$Housing->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Housing from the database
		$row = $this->_DB->getTopRow();

		$this->_Housing= new Housing();

		//preparing the Housing object
	    $this->_Housing->setID ( $row['id']);
	    $this->_Housing->setName( $row['name'] );
	    $this->_Housing->setTypeId( $row['type_id'] );
	    $this->_Housing->setFloor( $row['no_of_floor'] );
	    $this->_Housing->setRoom( $row['no_of_room'] );
	    

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Housing);

		return $Result;
	}

	

	//update an Housing object based on its 
	public function updateHousing($Housing){

		$SQL = "UPDATE hms_housing SET name='".$Housing->getName()."',				
				no_of_floor = '".$Housing->getFloor()."',
				no_of_room = '".$Housing->getRoom()."'
				
				WHERE id='".$Housing->getID()."'";

		
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Housing based on its id of the database
	public function deleteHousing($Housing){


		$SQL = "DELETE from hms_housing where id ='".$Housing->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}






	public function getNameFromID($ID){

		$SQL = "SELECT * FROM hms_housing WHERE id='".$ID."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_HousingType = new HousingType();

		$this->_HousingType->setID ( $row['id']);
		$this->_HousingType->setName( $row['name'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_HousingType);

		return $Result;
	}

}

?>