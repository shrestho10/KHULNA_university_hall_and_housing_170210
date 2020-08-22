 <?php

include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once UTILITY.'class.util.inc';

class SearchNoticeDAO
{
	private $_DB;
	private $_SearchNotice;

	function __construct(){
		$this->_DB = DBUtil::getInstance();
		$this->_SearchNotice = new SearchNotice();
	}

	public function getNotice($SearchField,$SearchText){

		$NoticeList = array();
		$SQL = "SELECT  r.* FROM hms_notice r WHERE r.".$SearchField." Like '%$SearchText%'";
        $this->_DB->doQuery($SQL);
		//$SQL = "SELECT * FROM hms_notice WHERE ".$SearchField." Like '$SearchText'";
		//$this->_DB->doQuery($SQL);

		$rows = $this->_DB->getAllRows();

		for ($i=0; $i < sizeof($rows); $i++) { 
			$row = $rows[$i];

			$this->_SearchNotice = new SearchNotice();

			$this->_SearchNotice->setId($row['id']);
			$this->_SearchNotice->setSubject($row['subject']);
			$this->_SearchNotice->setBody($row['body']);
			$this->_SearchNotice->setDate($row['app_date']);
			$this->_SearchNotice->setLinks( $row['link'] );


			$NoticeList[] = $this->_SearchNotice;
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($NoticeList);

		return $Result;
	}

	

    

	
}