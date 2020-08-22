 <?php

include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once UTILITY.'class.util.inc';

class ViewNoticeDAO
{
	private $_DB;
	private $_ViewNotice;

	function __construct(){
		$this->_DB = DBUtil::getInstance();
		$this->_ViewNotice = new ViewNotice();
	}

	public function getAllNotice(){

		$ApplicationList = array();

		$this->_DB->doQuery("SELECT * FROM hms_notice order by app_date DESC");

		$rows = $this->_DB->getAllRows();

		for ($i=0; $i < sizeof($rows); $i++) { 
			$row = $rows[$i];

			$this->_ViewNotice = new ViewNotice();

			$this->_ViewNotice->setId($row['id']);
			$this->_ViewNotice->setSubject($row['subject']);
			$this->_ViewNotice->setBody($row['body']);
			$this->_ViewNotice->setDate($row['app_date']);
			$this->_ViewNotice->setLinks( $row['link'] );


			$ApplicationList[] = $this->_ViewNotice;
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($ApplicationList);

		return $Result;
	}




	public function getNoticeById($Id){


		$SQL = "SELECT * from hms_notice WHERE id= '".$Id."' " ;
		$this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_ViewNotice= new ViewNotice();

	    $this->_ViewNotice->setId ( $row['id']);
	   // $this->_CreateNotice->setReceiver( $row['receiver'] );
	   
	    $this->_ViewNotice->setMyfile( $row['myfile'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_ViewNotice);

		return $Result;
	}

	

    

	
}