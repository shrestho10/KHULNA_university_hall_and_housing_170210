<?php


class HousingType{
    private $_ID;
    private $_name;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }
    public function setName ($Name){
        $this->_name = $Name;
    }
    public function getName(){
        return $this->_name;
    }
}

class Housing{
    private $_ID;
    private $_name;
    private $_no_of_floor;
    private $_no_of_room;
    private $_provost;
    private $_type_id;
    private $_hallid;



    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

      public function setHallId($hallid)
    {
        $this->_hallid = $hallid;
    }

    public function getHallId()
    {
        return $this->_hallid;
    }
    public function setName ($Name){
        $this->_name = $Name;
    }
    public function getName(){
        return $this->_name;
    }

    public function setTypeId ($type_id){
        $this->_type_id = $type_id;
    }
    public function getTypeId(){
        return $this->_type_id;
    }

    public function setFloor ($no_of_floor){
        $this->_no_of_floor = $no_of_floor;
    }
    public function getFloor(){
        return $this->_no_of_floor;
    }
    public function setRoom ($no_of_room){
        $this->_no_of_room = $no_of_room;
    }
    public function getRoom(){
        return $this->_no_of_room;
    }
    
    
}

//Class for Housing Details

class HousingProvost{
    private $_ID;
    
    private $_housing_id;
    private $_provost;
    private $_userid;
    
 
    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }
   
    public function setHousingId ($Hid){
        $this->_housing_id = $Hid;
    }
    public function getHousingId(){
        return $this->_housing_id;
    }

    public function setProvost ($provost){
        $this->_provost = $provost;
    }
    public function getProvost(){
        return $this->_provost;
    }

    public function setUserId($userid)
    {
        $this->_userid = $userid;
    }

    public function getUserId()
    {
        return $this->_userid;
    }
    
    
}

class HousingAssistantProvost{
    private $_ID;
    private $_housing_id;
    private $_ass_provost;
  
    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }
    public function setHousingId ($Hid){
        $this->_housing_id = $Hid;
    }
    public function getHousingId(){
        return $this->_housing_id;
    }

    
    public function setAssProvost ($ass_provost){
        $this->_ass_provost = $ass_provost;
    }
    public function getAssProvost(){
        return $this->_ass_provost;
    }
    
    
}

class HousingEmployee{
    private $_ID;
    private $_housing_id;
    private $_officer;
    
 
    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }
    public function setHousingId ($Hid){
        $this->_housing_id = $Hid;
    }
    public function getHousingId(){
        return $this->_housing_id;
    }

    
    public function setOfficer ($officer){
        $this->_officer = $officer;
    }
    public function getOfficer(){
        return $this->_officer;
    }
    
    
}

//Class for room
class HousingRoom{
    private $_room_id;
    private $_room_no;
    private $_house_id;
    private $_no_of_seat;

    public function setRoomId($room_id){
        $this->_room_id = $room_id;
    }
    public function getRoomId()
    {
        return $this->_room_id;
    }
    public function setRoomNo($room_no){
        $this->_room_no = $room_no;
    }
    public function getRoomNo()
    {
        return $this->_room_no;
    }
    public function setHouseId($house_id)
    {
        $this->_house_id = $house_id;
    }
    public function getHouseId()
    {
        return $this->_house_id;
    }
    public function setNoOfSeat($no_of_seat)
    {
        $this->_no_of_seat = $no_of_seat;
    }
    public function getNoOfSeat()
    {
        return $this->_no_of_seat;
    }
}

/**
* 
*/
class HousingRoomAssign
{
    private $_user_id;
    private $_house_id;
    private $_room_id;
    private $_currentDate;
    private $_appointDate;
    

    public function setUserId($user_id)
    {
        $this->_user_id = $user_id;
    }
    public function getUserId()
    {
        return $this->_user_id;
    }




     public function setCurrentDate($currentDate)
    {
        $this->_currentDate = $currentDate;
    }
    public function getCurrentDate()
    {
        return $this->_currentDate;
    }


     public function setAppointDate($appointDate)
    {
        $this->_appointDate = $appointDate;
    }
    public function getAppointDate()
    {
        return $this->_appointDate;
    }
    
    public function setHouseId($house_id)
    {
        $this->_house_id = $house_id;
    }
    public function getHouseId()
    {
        return $this->_house_id;
    }

    public function setRoomId($room_id){
        $this->_room_id = $room_id;
    }
    public function getRoomId()
    {
        return $this->_room_id;
    }
    
}

class HousingApplication
{
    private $_id;
    private $_template_id;
    
    private $_body;
    private $_user_id;
    private $_date;

    public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }

    public function setTemplateId($template_id)
    {
        $this->_template_id = $template_id;
    }

    public function getTemplateId()
    {
        return $this->_template_id;
    }

    public function setUserId($user_id)
    {
        $this->_user_id = $user_id;
    }

    public function getUserId()
    {
        return $this->_user_id;
    }


    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }

    public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }
}

class HousingDiscipline
{
    private $_ID;
    private $_Name;
    private $_ShortCode;
    private $_SchoolId;

    public function setID($ID)
    {
        $this->_ID = $ID;
    }

    public function getID()
    {
        return $this->_ID;
    }

    public function setName($Name)
    {
        $this->_Name = $Name;
    }

    public function getName()
    {
        return $this->_Name;
    }

    public function setShortCode($ShortCode)
    {
        $this->_ShortCode = $ShortCode;
    }

    public function getShortCode()
    {
        return $this->_ShortCode;
    }

    public function setSchoolID($SchoolID)
    {
        $this->_SchoolId = $SchoolID;
    }

    public function getSchoolID()
    {
        return $this->_SchoolId;
    }

}

class ApplicationTemplate
{
    private $_id;
    private $_subject;
    private $_receiver;
    private $_body;

    public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }

    public function setSubject($subject)
    {
        $this->_subject = $subject;
    }

    public function getSubject()
    {
        return $this->_subject;
    }

    public function setReceiver($receiver)
    {
        $this->_receiver = $receiver;
    }

    public function getReceiver()
    {
        return $this->_receiver;
    }

    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }
}


class CreateNotice
{
    
    
 private $_id;

    private $_subject;
    
    private $_body;
   private $_links;


    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }

    public function setSubject($subject)
    {
        $this->_subject = $subject;
    }

    public function getSubject()
    {
        return $this->_subject;
    }

    


    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }


     public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }

    public function setMyFile($myfile)
    {
        $this->_myfile = $myfile;
    }

    public function getMyFile()
    {
        return $this->_myfile;
    }


       public function getLinks()
    {
        return $this->_links;
    }

  
    public function setLinks($links)
    {
        $this->_links = $links;
    }
}


class ViewNotice
{
    
    
 private $_id;

    private $_subject;
    
    private $_body;
     private $_myfile;
private $_link;
    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }

    public function setSubject($subject)
    {
        $this->_subject = $subject;
    }

    public function getSubject()
    {
        return $this->_subject;
    }

    


    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }


     public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }
    public function setMyFile($myfile)
    {
        $this->_myfile = $myfile;
    }

    public function getMyFile()
    {
        return $this->_myfile;
    }


     public function getLinks()
    {
        return $this->_links;
    }

  
    public function setLinks($links)
    {
        $this->_links = $links;
    }
}


class SearchNotice
{
    
    
 private $_id;

    private $_subject;
    
    private $_body;
    private $_links;

    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }

    public function setSubject($subject)
    {
        $this->_subject = $subject;
    }

    public function getSubject()
    {
        return $this->_subject;
    }

    


    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }


     public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }

      public function getLinks()
    {
        return $this->_links;
    }

  
    public function setLinks($links)
    {
        $this->_links = $links;
    }
}

class CreateComplain
{
    
    
 private $_id;
 private $_complainAgainst;

 private $_complainBy;


    private $_subject;
    
    private $_body;
   
    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }
     public function setComplainAgainst($complainAgainst)
    {
        $this->_complainAgainst = $complainAgainst;
    }

    public function getComplainAgainst()
    {
        return $this->_complainAgainst;
    }

    public function setComplainBy($complainBy)
    {
        $this->_complainBy = $complainBy;
    }

    public function getComplainBy()
    {
        return $this->_complainBy;
    }

    public function setSubject($subject)
    {
        $this->_subject = $subject;
    }

    public function getSubject()
    {
        return $this->_subject;
    }

    


    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }


     public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }



   

}



class ViewComplain
{
    
    
 private $_id;
 private $_complainAgainst;

 private $_complainBy;


    private $_subject;
    
    private $_body;

    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }
     public function setComplainAgainst($complainAgainst)
    {
        $this->_complainAgainst = $complainAgainst;
    }

    public function getComplainAgainst()
    {
        return $this->_complainAgainst;
    }

    public function setComplainBy($complainBy)
    {
        $this->_complainBy = $complainBy;
    }

    public function getComplainBy()
    {
        return $this->_complainBy;
    }

    public function setSubject($subject)
    {
        $this->_subject = $subject;
    }

    public function getSubject()
    {
        return $this->_subject;
    }

    


    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }


     public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }
}







class ApplyForSeat
{
    
    
 private $_id;
 private $_userid;
 private $_hallname;

 private $_body;
  private $_date;


   

    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }
    
     public function setUserID ( $userid ) {
        $this->_userid = $userid;
    }

    public function getUserID () {
        return $this->_userid;
    }

    public function setHallName($hallname)
    {
        $this->_hallname = $hallname;
    }

    public function getHallName()
    {
        return $this->_hallname;
    }

    public function setFile($file)
    {
        $this->_file = $file;
    }

    public function getFile()
    {
        return $this->_file;
    }

     public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }
    public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }

    
}



class Interview
{
    
    
 private $_id;
 private $_userid;
 private $_date;

 private $_time;
 private $_hallid;
 private $_status;
 private $_seat;




   

    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }
    
     public function setUserID ($userid) {
        $this->_userid = $userid;
    }

    public function getUserID () {
        return $this->_userid;
    }

    public function setAppDate($date)
    {
        $this->_date = $date;
    }

    public function getAppDate()
    {
        return $this->_date;
    }

    public function setTime($time)
    {
        $this->_time = $time;
    }

    public function getTime()
    {
        return $this->_time;
    }

    public function setHallId($hallid)
    {
        $this->_hallid = $hallid;
    }

    public function getHallId()
    {
        return $this->_hallid;
    }


    public function setStatus($status)
    {
        $this->_status = $status;
    }

    public function getStatus()
    {
        return $this->_status;
    }
    public function setSeat($seat)
    {
        $this->_seat = $seat;
    }

    public function getSeat()
    {
        return $this->_seat;
    }

   

    
}




class History
{
    
    
 private $_id;
 private $_userid;
 private $_houseid;
 private $_roomid;
 private $_appdate;
 private $_leavedate;




   

    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }
    public function setHouseId($id)
    {
        $this->_houseid = $id;
    }

    public function getHouseId()
    {
        return $this->_houseid;
    }
    public function setRoomId($id)
    {
        $this->_roomid = $id;
    }

    public function getRoomId()
    {
        return $this->_roomid;
    }
    
     public function setUserID ($userid) {
        $this->_userid = $userid;
    }

    public function getUserID () {
        return $this->_userid;
    }

    public function setAppDate($date)
    {
        $this->_appdate = $date;
    }

    public function getAppDate()
    {
        return $this->_appdate;
    }

    public function setLeaveDate($date)
    {
        $this->_leavedate = $date;
    }

    public function getLeaveDate()
    {
        return $this->_leavedate;
    }

    

   

    
}



class viewApplicants
{
    
    
 private $_id;

    private $_userid;
    
    private $_body;
   private $_links;
   private $_hallid;
   private $_status;
   private $_date;


    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }

    public function setUserId($userid)
    {
        $this->_userid = $userid;
    }

    public function getUserId()
    {
        return $this->_userid;
    }

    


    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }


     public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }

    public function setMyFile($myfile)
    {
        $this->_myfile = $myfile;
    }

    public function getMyFile()
    {
        return $this->_myfile;
    }


       public function getLinks()
    {
        return $this->_links;
    }

  
    public function setLinks($links)
    {
        $this->_links = $links;
    }

    public function setHallId($hallid)
    {
        $this->_hallid = $hallid;
    }

    public function getHallId()
    {
        return $this->_hallid;
    }

      public function setStatus($status)
    {
        $this->_status = $status;
    }

    public function getStatus()
    {
        return $this->_status;
    }


}




class CreateIssue
{
    
    
 private $_id;

    private $_subject;
    
    private $_body;
   private $_links;


    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }

    public function setSubject($subject)
    {
        $this->_subject = $subject;
    }

    public function getSubject()
    {
        return $this->_subject;
    }

    


    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }


     public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }

    public function setMyFile($myfile)
    {
        $this->_myfile = $myfile;
    }

    public function getMyFile()
    {
        return $this->_myfile;
    }


       public function getLinks()
    {
        return $this->_links;
    }

  
    public function setLinks($links)
    {
        $this->_links = $links;
    }
}




class InterviewList
{
    
    
 private $_id;
 private $_userid;
 private $_date;

 private $_time;
 private $_hallid;
 private $_status;
  private $_seat;



   

    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }
    
     public function setUserID ($userid) {
        $this->_userid = $userid;
    }

    public function getUserID () {
        return $this->_userid;
    }

    public function setAppDate($date)
    {
        $this->_date = $date;
    }

    public function getAppDate()
    {
        return $this->_date;
    }

    public function setTime($time)
    {
        $this->_time = $time;
    }

    public function getTime()
    {
        return $this->_time;
    }

    public function setHallId($hallid)
    {
        $this->_hallid = $hallid;
    }

    public function getHallId()
    {
        return $this->_hallid;
    }

    public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }
      public function setStatus($status)
    {
        $this->_status = $status;
    }

    public function getStatus()
    {
        return $this->_status;
    }

     public function setSeat($seat)
    {
        $this->_seat = $seat;
    }

    public function getSeat()
    {
        return $this->_seat;
    }

   

    
}


class ViewIssue
{
    
    
 private $_id;

    private $_subject;
    
    private $_body;
   private $_links;


    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }

    public function setSubject($subject)
    {
        $this->_subject = $subject;
    }

    public function getSubject()
    {
        return $this->_subject;
    }

    


    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }


     public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }

    public function setMyFile($myfile)
    {
        $this->_myfile = $myfile;
    }

    public function getMyFile()
    {
        return $this->_myfile;
    }


       public function getLinks()
    {
        return $this->_links;
    }

  
    public function setLinks($links)
    {
        $this->_links = $links;
    }
}



class CreateBlacklist
{
    
    
 private $_id;
 private $_userid;

    private $_subject;
    
    private $_body;
   private $_links;


    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }

    public function setUserId($userid)
    {
        $this->_userid = $userid;
    }

    public function getUserId()
    {
        return $this->_userid;
    }

    public function setSubject($subject)
    {
        $this->_subject = $subject;
    }

    public function getSubject()
    {
        return $this->_subject;
    }

    


    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }


     public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }

    public function setMyFile($myfile)
    {
        $this->_myfile = $myfile;
    }

    public function getMyFile()
    {
        return $this->_myfile;
    }


       public function getLinks()
    {
        return $this->_links;
    }

  
    public function setLinks($links)
    {
        $this->_links = $links;
    }
}


class SearchBlacklist
{
    
    
 private $_id;
 private $_userid;

    private $_subject;
    
    private $_body;
    private $_links;

    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }



    public function setUserId($userid)
    {
        $this->_userid = $userid;
    }

    public function getUserId()
    {
        return $this->_userid;
    }

    public function setSubject($subject)
    {
        $this->_subject = $subject;
    }

    public function getSubject()
    {
        return $this->_subject;
    }

    


    public function setBody($body)
    {
        $this->_body = $body;
    }

    public function getBody()
    {
        return $this->_body;
    }


     public function setDate($date)
    {
        $this->_date = $date;
    }

    public function getDate()
    {
        return $this->_date;
    }

      public function getLinks()
    {
        return $this->_links;
    }

  
    public function setLinks($links)
    {
        $this->_links = $links;
    }
}






class HallPermission
{
    
    
 private $_id;

    private $_idd;
    
    private $_hallid;
    

    
  public function setId($id)
    {
        $this->_id = $id;
    }

    public function getId()
    {
        return $this->_id;
    }



     public function setIdd($idd)
    {
        $this->_idd = $idd;
    }

    public function getIdd()
    {
        return $this->_idd;
    }

    


 public function setHallId($hallid)
    {
        $this->_hallid = $hallid;
    }

    public function getHallId()
    {
        return $this->_hallid;
    }

    


    
}




?>