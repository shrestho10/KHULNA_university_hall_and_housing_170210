<?php

include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once UTILITY.'class.util.inc';

class HallPermissionDAO
{
	private $_DB;
	
	private $_HallPermission;

	function __construct(){
		$this->_DB = DBUtil::getInstance();
		$this->_HousingDiscipline = new HousingDiscipline();
		$this->_HallPermission = new HallPermission();
	}



public function HallPermission($HallPermission){
		


		$Id=$HallPermission->getId();
        $Idd = $HallPermission->getIdd();
        $hid = $HallPermission->getHallId();
		

		$SQL = $this->_DB->doQuery("INSERT INTO hallpermission(id,userid,hallid) VALUES('$Id','$Idd','$hid')");

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}	





	public function getAllHallPermission($h){

		$HallPermissionList = array();

		$this->_DB->doQuery("SELECT * FROM hallpermission WHERE hallid = '".$h."'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_HallPermission = new HallPermission();

		    $this->_HallPermission->setId ( $row['id']);
		   // $this->_HallPermission->setReceiver( $row['receiver'] );
		    $this->_HallPermission->setIdd( $row['userid'] );
		    $this->_HallPermission->setHallId( $row['hallid'] );
		  
		    //$this->_HallPermission->setMyFile( $row['myfile'] );


		    $HallPermissionList[]=$this->_HallPermission;

		}
        
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($HallPermissionList);

		return $Result;
	}

	

	public function updateHallPermission($HallPermission){

		$SQL = "UPDATE hallpermission SET userid='".$HallPermission->getIdd()."'
				WHERE id='".$HallPermission->getId()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	public function deleteHallPermission($HallPermission){

       

	

		



		$SQL = "DELETE from hallpermission where id ='".$HallPermission->getId()."'";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	public function readHallPermission($HallPermission){


		$SQL = "SELECT * from hallpermission WHERE id='".$HallPermission->getId()."'";
		$this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_HallPermission= new HallPermission();

	    
	   $this->_HallPermission->setId ( $row['id']);
		   // $this->_HallPermission->setReceiver( $row['receiver'] );
		    $this->_HallPermission->setIdd( $row['userid'] );
		    $this->_HallPermission->setHallId( $row['hallid'] );;



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_HallPermission);

		return $Result;
	}

}