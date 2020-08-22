<?php

include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once UTILITY.'class.util.inc';

class CreateNoticeDAO
{
	private $_DB;
	
	private $_CreateNotice;

	function __construct(){
		$this->_DB = DBUtil::getInstance();
		$this->_HousingDiscipline = new HousingDiscipline();
		$this->_CreateNotice = new CreateNotice();
	}

	

	

	public function getNoticeBody($id){
		$SQL = "SELECT * FROM hms_notice WHERE id='".$id."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_CreateNotice = new CreateNotice();

		$this->_CreateNotice->setSubject ( $row['subject']);
		$this->_CreateNotice->setId( $row['id'] );
		$this->_CreateNotice->setBody( $row['body'] );
		//$this->_CreateNotice->setMyFile( $row['myfile'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CreateNotice);

		return $Result;
	}

	public function createNotice($CreateNotice){
		


		$Id=$CreateNotice->getId();
        $Subject = $CreateNotice->getSubject();
		$Body = $CreateNotice->getBody();
		$App_Date = $CreateNotice->getDate();
		$Link=$CreateNotice->getLinks();

		$SQL = $this->_DB->doQuery("INSERT INTO hms_notice(id,subject,body,app_date,link) VALUES('$Id','$Subject','$Body', '$App_Date','$Link')");

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}






	public function getAllNotice(){

		$CreateNoticeList = array();

		$this->_DB->doQuery("SELECT * FROM hms_notice");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_CreateNotice = new CreateNotice();

		    $this->_CreateNotice->setId ( $row['id']);
		   // $this->_CreateNotice->setReceiver( $row['receiver'] );
		    $this->_CreateNotice->setSubject( $row['subject'] );
		    $this->_CreateNotice->setBody( $row['body'] );
		    $this->_CreateNotice->setLinks( $row['link'] );
		    //$this->_CreateNotice->setMyFile( $row['myfile'] );


		    $CreateNoticeList[]=$this->_CreateNotice;

		}
        
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CreateNoticeList);

		return $Result;
	}

	

	public function updateCreateNotice($CreateNotice){

		$SQL = "UPDATE hms_notice SET subject='".$CreateNotice->getSubject()."',body='".$CreateNotice->getBody()."',link='".$CreateNotice->getLinks()."'
				WHERE id='".$CreateNotice->getId()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	public function deleteCreateNotice($CreateNotice){

        $SQL1 = "SELECT * FROM hms_notice where id ='".$CreateNotice->getId()."'";

		$SQL1 = $this->_DB->doQuery($SQL1);

		$row = $this->_DB->getTopRow();

		$this->_CreateNotice = new CreateNotice();

		$this->_CreateNotice->setLinks ( $row['link']);

		if(unlink($row['link']))
		{
			echo"well done";
		}



		$SQL = "DELETE from hms_notice where id ='".$CreateNotice->getId()."'";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	public function readCreateNotice($CreateNotice){


		$SQL = "SELECT * from hms_notice WHERE id='".$CreateNotice->getId()."'";
		$this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_CreateNotice= new CreateNotice();

	    $this->_CreateNotice->setId ( $row['id']);
	   // $this->_CreateNotice->setReceiver( $row['receiver'] );
	    $this->_CreateNotice->setSubject( $row['subject'] );
	    $this->_CreateNotice->setBody( $row['body'] );
	    $this->_CreateNotice->setLinks ( $row['link']);



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CreateNotice);

		return $Result;
	}
}