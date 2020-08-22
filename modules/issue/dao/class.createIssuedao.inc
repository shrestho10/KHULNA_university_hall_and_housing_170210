<?php

include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once UTILITY.'class.util.inc';

class CreateIssueDAO
{
	private $_DB;
	
	private $_CreateIssue;

	function __construct(){
		$this->_DB = DBUtil::getInstance();
		$this->_HousingDiscipline = new HousingDiscipline();
		$this->_CreateIssue = new CreateIssue();
	}

	

	

	public function getIssueBody($id){
		$SQL = "SELECT * FROM hms_issue WHERE id='".$id."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_CreateIssue = new CreateIssue();

		$this->_CreateIssue->setSubject ( $row['subject']);
		$this->_CreateIssue->setId( $row['id'] );
		$this->_CreateIssue->setBody( $row['body'] );
		//$this->_CreateIssue->setMyFile( $row['myfile'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CreateIssue);

		return $Result;
	}

	public function CreateIssue($CreateIssue){
		


		$Id=$CreateIssue->getId();
        $Subject = $CreateIssue->getSubject();
		$Body = $CreateIssue->getBody();
		$App_Date = $CreateIssue->getDate();
		$Link=$CreateIssue->getLinks();

		$SQL = $this->_DB->doQuery("INSERT INTO hms_issue(id,subject,body,app_date,link) VALUES('$Id','$Subject','$Body', '$App_Date','$Link')");

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}






	public function getAllIssue(){

		$CreateIssueList = array();

		$this->_DB->doQuery("SELECT * FROM hms_issue");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_CreateIssue = new CreateIssue();

		    $this->_CreateIssue->setId ( $row['id']);
		   // $this->_CreateIssue->setReceiver( $row['receiver'] );
		    $this->_CreateIssue->setSubject( $row['subject'] );
		    $this->_CreateIssue->setBody( $row['body'] );
		    $this->_CreateIssue->setLinks( $row['link'] );
		    //$this->_CreateIssue->setMyFile( $row['myfile'] );


		    $CreateIssueList[]=$this->_CreateIssue;

		}
        
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CreateIssueList);

		return $Result;
	}

	

	public function updateCreateIssue($CreateIssue){

		$SQL = "UPDATE hms_issue SET subject='".$CreateIssue->getSubject()."',body='".$CreateIssue->getBody()."',link='".$CreateIssue->getLinks()."'
				WHERE id='".$CreateIssue->getId()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	public function deleteCreateIssue($CreateIssue){

        $SQL1 = "SELECT * FROM hms_issue where id ='".$CreateIssue->getId()."'";

		$SQL1 = $this->_DB->doQuery($SQL1);

		$row = $this->_DB->getTopRow();

		$this->_CreateIssue = new CreateIssue();

		$this->_CreateIssue->setLinks ( $row['link']);

		if(unlink($row['link']))
		{
			echo"well done";
		}



		$SQL = "DELETE from hms_issue where id ='".$CreateIssue->getId()."'";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	public function readCreateIssue($CreateIssue){


		$SQL = "SELECT * from hms_issue WHERE id='".$CreateIssue->getId()."'";
		$this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_CreateIssue= new CreateIssue();

	    $this->_CreateIssue->setId ( $row['id']);
	   // $this->_CreateIssue->setReceiver( $row['receiver'] );
	    $this->_CreateIssue->setSubject( $row['subject'] );
	    $this->_CreateIssue->setBody( $row['body'] );
	    $this->_CreateIssue->setLinks ( $row['link']);



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CreateIssue);

		return $Result;
	}
}