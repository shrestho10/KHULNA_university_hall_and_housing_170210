 <?php

include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once UTILITY.'class.util.inc';

class ViewIssueDAO
{
	private $_DB;
	private $_ViewIssue;

	function __construct(){
		$this->_DB = DBUtil::getInstance();
		$this->_ViewIssue = new ViewIssue();
	}

	public function getAllIssue(){

		$ApplicationList = array();

		$this->_DB->doQuery("SELECT * FROM hms_issue order by app_date DESC");

		$rows = $this->_DB->getAllRows();

		for ($i=0; $i < sizeof($rows); $i++) { 
			$row = $rows[$i];

			$this->_ViewIssue = new ViewIssue();

			$this->_ViewIssue->setId($row['id']);
			$this->_ViewIssue->setSubject($row['subject']);
			$this->_ViewIssue->setBody($row['body']);
			$this->_ViewIssue->setDate($row['app_date']);
			$this->_ViewIssue->setLinks( $row['link'] );


			$ApplicationList[] = $this->_ViewIssue;
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($ApplicationList);

		return $Result;
	}




	public function getIssueById($Id){


		$SQL = "SELECT * from hms_Issue WHERE id= '".$Id."' " ;
		$this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_ViewIssue= new ViewIssue();

	    $this->_ViewIssue->setId ( $row['id']);
	   // $this->_CreateIssue->setReceiver( $row['receiver'] );
	   
	    $this->_ViewIssue->setMyfile( $row['myfile'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_ViewIssue);

		return $Result;
	}

	

    

	
}