<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once COMMON.'class.common.user.inc';
include_once UTILITY.'class.util.inc';
include_once MODULES_HOUSING_DAO.'class.housingdao.inc';


Class HousingRoomAssignDAO{

	private $_DB;
	private $_HousingRoomAssign;
	private $_History;
	
	function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_HousingRoomAssign= new HousingRoomAssign();
		

	}

	// get all the Housing Room Assign from the database using the database query
	public function getAllHousingRoomAssign($hid,$rid){

		$HousingRoomAssignList = array();

		$this->_DB->doQuery("SELECT * FROM hms_assign WHERE house_id = '".$hid."' and room_id = '".$rid."'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_HousingRoomAssign = new HousingRoomAssign();
			$this->_HousingRoomAssign->setUserId( $row['user_id'] );
			$this->_HousingRoomAssign->setHouseId( $row['house_id'] );
		    $this->_HousingRoomAssign->setRoomId ( $row['room_id']);

		    $HousingRoomAssignList[]=$this->_HousingRoomAssign;
   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($HousingRoomAssignList);

		return $Result;
	}

	public function getAllHousingUsers(){

		$HousingUserList = array();

		//$this->_DB->doQuery("SELECT * FROM tbl_user");
		$this->_DB->doQuery("SELECT * FROM tbl_user WHERE ID NOT IN (SELECT user_id FROM hms_assign)");


		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_HousingUser = new User();
			$this->_HousingUser->setID( $row['ID'] );
			$this->_HousingUser->setUniversityID( $row['UniversityID'] );
		    

		    $HousingUserList[]=$this->_HousingUser;
   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($HousingUserList);

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

	public function getUserFromId($uid){

		$SQL = "SELECT * FROM tbl_user WHERE ID='".$uid."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_User = new User();

		$this->_User->setID ( $row['ID']);
		$this->_User->setUniversityID( $row['UniversityID'] );
		$this->_User->setEmail( $row['Email'] );
		$this->_User->setFirstName( $row['FirstName'] );
		$this->_User->setLastName( $row['LastName'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_User);

		return $Result;
	}

	public function getUserFromUniversityID($uid){

		$SQL = "SELECT * FROM tbl_user WHERE UniversityID='".$uid."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_User = new User();

		$this->_User->setID ( $row['ID']);
		$this->_User->setUniversityID( $row['UniversityID'] );
		$this->_User->setEmail( $row['Email'] );
		$this->_User->setFirstName( $row['FirstName'] );
		$this->_User->setLastName( $row['LastName'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_User);

		return $Result;
	}

	public function getNumberOfUsersFromRoom($hid,$rid){
		
		$SQL = "SELECT count(*) FROM hms_assign WHERE house_id='".$hid."' and room_id='".$rid."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = mysqli_fetch_assoc($SQL);
		$size = $row['count(*)'];
		$_SESSION["countUsers"] = $size;

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);
		


		return $Result;
	}

	public function getTotalUserInRoom($hid,$rid){
		
		$SQL = "SELECT no_of_seat FROM hms_room WHERE house_id='".$hid."' and room_id='".$rid."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = mysqli_fetch_assoc($SQL);
		$size = $row['no_of_seat'];
		$_SESSION["totalUsers"] = $size;

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);
		


		return $Result;
	}

	public function getRoomNoFromId($rid){

		$SQL = "SELECT * FROM hms_room WHERE room_id='".$rid."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_HousingRoom = new HousingRoom();

		$this->_HousingRoom->setRoomId ( $row['room_id']);
		$this->_HousingRoom->setRoomNo( $row['room_no'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_HousingRoom);

		return $Result;
	}


	//create Housing Room Assign funtion with the Housing object
	public function createHousingRoomAssign($HousingRoomAssign){

		$UserId=$HousingRoomAssign->getUserId();
		$HousingId=$HousingRoomAssign->getHouseId();
		$RoomId=$HousingRoomAssign->getRoomId();
		$date=$HousingRoomAssign->getAppointDate();
		$Assign= $RoomId;

        $SQL3 = $this->_DB->doQuery("SELECT * FROM tbl_user WHERE Email='".$UserId."'");
        $row = $this->_DB->getTopRow();
        $ID=$row['UniversityID'];

        $SQL4 = $this->_DB->doQuery("SELECT * FROM hms_room WHERE room_id='".$RoomId."'");
        $row = $this->_DB->getTopRow();
        $ROOM=$row['room_no'];




		$SQL="SELECT * FROM hms_assign WHERE hms_assign.user_id='".$UserId."'";
		$this->_DB->doQuery($SQL);
		$rows=$this->_DB->getAllRows();
		if (empty($rows)) {

		$SQL = "INSERT INTO hms_assign (user_id,house_id,room_id,date)VALUES('$UserId','$HousingId','$RoomId','$date')";
		$SQL = $this->_DB->doQuery($SQL);
		
		$SQL2 = $this->_DB->doQuery("UPDATE  hms_interview SET seat = '".$ROOM."' WHERE userid ='".$ID."'");

		
	
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
		}
		else{
			$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject($SQL);

			return $Result;
		}
	}

	


	//read an Housing Room Assign object based on its id form Housing object
	public function readHousingRoomAssign($HousingRoomAssign){
		
		
		$SQL = "SELECT * FROM hms_assign WHERE room_id='".$HousingRoomAssign->getRoomId()."'";
		$this->_DB->doQuery($SQL);


		//reading the top row for this Housing Room Assign from the database
		$row = $this->_DB->getTopRow();

		$this->_HousingRoomAssign= new HousingRoomAssign();

		//preparing the Housing Room Assign object
	    $this->_HousingRoomAssign->setRoomId ( $row['room_id']);
	    $this->_HousingRoomAssign->setUserId( $row['user_id'] );
	    $this->_HousingRoomAssign->setHouseId( $row['house_id'] );
	    
	    




	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_HousingRoomAssign);

		return $Result;
	}

	

	//delete an Housing Room Assign based on its id of the database
	public function deleteHousingRoomAssign($HousingRoomAssign){

		$UserId=$HousingRoomAssign->getUserId();
		$HousingId=$HousingRoomAssign->getHouseId();
		$RoomId=$HousingRoomAssign->getRoomId();

		$SQL = "SELECT * FROM hms_assign WHERE user_id='".$UserId."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_HousingRoomAssign= new HousingRoomAssign();

		//preparing the Housing Room Assign object
	    $date1= $row['date'];
	  


		


		$date=$HousingRoomAssign->getCurrentDate();;
		
		$SQL1="	INSERT into hms_history(userid,roomid,houseid,date,appdate) 
		VALUES('$UserId','$RoomId','$HousingId','$date','$date1') " ;
		

       $SQL1 = $this->_DB->doQuery($SQL1);

	 	

		
		$SQL = "DELETE from hms_assign where user_id ='".$HousingRoomAssign->getUserId()."'";
		
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
		

	}


	public function getHistoryFromId($id){
		$HistoryList = array();

		$this->_DB->doQuery("SELECT * FROM hms_history WHERE userid='".$id."'");
		

		$rows = $this->_DB->getAllRows();

		for ($i=0; $i < sizeof($rows); $i++) { 
			$row = $rows[$i];

		$this->_History = new History();
        $this->_History->setRoomId ( $row['houseid']);
        $this->_History->setAppDate ( $row['appdate']);
        $this->_History->setLeaveDate ( $row['date']);
     
		$HistoryList[]= $this->_History;
		}
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($HistoryList);

		return $Result;
	}

	






}

?>