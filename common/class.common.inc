<?php
include_once 'class.common.user.inc';


/*All the common Model classes are listed here*/
class PermissionXML{
    var $id;  // id of permission
    var $name;    // name of permission
    var $category;  // category of permission
    
    //map the tag, value pair with the members serially
    //used in xml to permission mapping
    public function __construct($row) {

        //todo: check for the exception situation

        foreach ($row as $k=>$v)
            $this->$k = $row[$k];

    }

}

class MenuXML{
    private $_ParentTitle;
    public $_Child;
    private $_Title;
    private $_Permissions;
    private $_Link;
    private $_Visible=0; // by default every menu is in visible

    public function getTitle(){
        return $this->_Title;
    }

    public function setTitle($Title){
        $this->_Title = $Title;
    }


    public function getParentTitle(){
        return $this->_ParentTitle;
    }

    public function setParentTitle($ParentTitle){
        $this->_ParentTitle = $ParentTitle; 
    }

    public function getPermissions(){
        return $this->_Permissions;
    }

    public function setPermissions($Permissions){
        $this->_Permissions = $Permissions;
    }

    public function getLink(){
        return $this->_Link;
    }

    public function setLink($Link){
        $this->_Link = $Link;
    }

    public function setVisible($Visible){
        $this->_Visible = $Visible;
    }

    public function isVisible(){

        return $this->_Visible;
    }

}


class Result{

    private $_IsSuccess=0;
    private $_ResultObject;

    public function setIsSuccess($IsSuccess){
        $this->_IsSuccess = $IsSuccess;
    }

    public function getIsSuccess(){

        return $this->_IsSuccess;
    }

    public function setResultObject($ResultObject){
        $this->_ResultObject = $ResultObject;
    }

    public function getResultObject(){

        return $this->_ResultObject;
    }

}

class Result1{

    private $_IsSuccess=0;
    private $_ResultObject;

    public function setIsSuccess($IsSuccess){
        $this->_IsSuccess = $IsSuccess;
    }

    public function getIsSuccess(){

        return $this->_IsSuccess;
    }

    public function setResultObject($ResultObject){
        $this->_ResultObject = $ResultObject;
    }

    public function getResultObject(){

        return $this->_ResultObject;
    }

}



class PermissionUtil{


    public static $DISCUSSION_C='DISCUSSION_C';
    public static $DISCUSSION_R='DISCUSSION_R';
    public static $DISCUSSION_U='DISCUSSION_U';
    public static $DISCUSSION_D='DISCUSSION_D';

    public static $DISCUSSION_CAT_C='DISCUSSION_CAT_C';
    public static $DISCUSSION_CAT_R='DISCUSSION_CAT_R';
    public static $DISCUSSION_CAT_U='DISCUSSION_CAT_U';
    public static $DISCUSSION_CAT_D='DISCUSSION_CAT_D';

    public static $DISCUSSION_COMMENT_C='DISCUSSION_COMMENT_C';
    public static $DISCUSSION_COMMENT_R='DISCUSSION_COMMENT_R';
    public static $DISCUSSION_COMMENT_U='DISCUSSION_COMMENT_U';
    public static $DISCUSSION_COMMENT_D='DISCUSSION_COMMENT_D';


    public static $HALL_C='HALL_C';
    public static $HALL_R='HALL_R';
    public static $HALL_U='HALL_U';
    public static $HALL_D='HALL_D';


    public static $POSITION_C='POSITION_C';
    public static $POSITION_R='POSITION_R';
    public static $POSITION_U='POSITION_U';
    public static $POSITION_D='POSITION_D';

    public static $ROLE_C='ROLE_C';
    public static $ROLE_R='ROLE_R';
    public static $ROLE_U='ROLE_U';
    public static $ROLE_D='ROLE_D';

    public static $SCHOOL_C='SCHOOL_C';
    public static $SCHOOL_R='SCHOOL_R';
    public static $SCHOOL_U='SCHOOL_U';
    public static $SCHOOL_D='SCHOOL_D';


    public static $USER_C='USER_C';
    public static $USER_R='USER_R';
    public static $USER_U='USER_U';
    public static $USER_D='USER_D';

    public static $DISCIPLINE_C='DISCIPLINE_C';
    public static $DISCIPLINE_R='DISCIPLINE_R';
    public static $DISCIPLINE_U='DISCIPLINE_U';
    public static $DISCIPLINE_D='DISCIPLINE_D';
   
    public static $PERMISSION_C='PERMISSION_C';
    public static $PERMISSION_R='PERMISSION_R';
    public static $PERMISSION_U='PERMISSION_U';
    public static $PERMISSION_D='PERMISSION_D';

       //Permission for housing
    public static $HOUSING_C='HOUSING_C';
    public static $HOUSING_R='HOUSING_R';
    public static $HOUSING_U='HOUSING_U';
    public static $HOUSING_D='HOUSING_D';

    public static $HOUSING_M_C='HOUSING_M_C';
    public static $HOUSING_M_R='HOUSING_M_R';
    public static $HOUSING_M_U='HOUSING_M_U';
    public static $HOUSING_M_D='HOUSING_M_D';

    public static $HOUSING_NEW_C='HOUSING_NEW_C';
    public static $HOUSING_NEW_R='HOUSING_NEW_R';
    public static $HOUSING_NEW_U='HOUSING_NEW_U';
    public static $HOUSING_NEW_D='HOUSING_NEW_D';

    public static $HOUSING_TYPE_C='HOUSING_TYPE_C';
    public static $HOUSING_TYPE_R='HOUSING_TYPE_R';
    public static $HOUSING_TYPE_U='HOUSING_TYPE_U';
    public static $HOUSING_TYPE_D='HOUSING_TYPE_D';

    public static $HOUSING_ROOM_C='HOUSING_ROOM_C';
    public static $HOUSING_ROOM_R='HOUSING_ROOM_R';
    public static $HOUSING_ROOM_U='HOUSING_ROOM_U';
    public static $HOUSING_ROOM_D='HOUSING_ROOM_D';

    public static $HOUSING_DETAILS_C='HOUSING_DETAILS_C';
    public static $HOUSING_DETAILS_R='HOUSING_DETAILS_R';
    public static $HOUSING_DETAILS_U='HOUSING_DETAILS_U';
    public static $HOUSING_DETAILS_D='HOUSING_DETAILS_D';

    public static $HOUSING_ROOM_ASSIGN_C='HOUSING_ROOM_ASSIGN_C';
    public static $HOUSING_ROOM_ASSIGN_R='HOUSING_ROOM_ASSIGN_R';
    public static $HOUSING_ROOM_ASSIGN_U='HOUSING_ROOM_ASSIGN_U';
    public static $HOUSING_ROOM_ASSIGN_D='HOUSING_ROOM_ASSIGN_D';

    public static $HOUSING_SEARCH_C='HOUSING_SEARCH_C';
    public static $HOUSING_SEARCH_R='HOUSING_SEARCH_R';
    public static $HOUSING_SEARCH_U='HOUSING_SEARCH_U';
    public static $HOUSING_SEARCH_D='HOUSING_SEARCH_D';

    public static $HOUSING_APPLICATION_C = 'HOUSING_APPLICATION_C';
    public static $HOUSING_APPLICATION_R = 'HOUSING_APPLICATION_R';
    public static $HOUSING_APPLICATION_U = 'HOUSING_APPLICATION_U';
    public static $HOUSING_APPLICATION_D = 'HOUSING_APPLICATION_D';

    public static $HOUSING_APPLICATION_MANAGE_C = 'HOUSING_APPLICATION_MANAGE_C';
    public static $HOUSING_APPLICATION_MANAGE_R = 'HOUSING_APPLICATION_MANAGE_R';
    public static $HOUSING_APPLICATION_MANAGE_U = 'HOUSING_APPLICATION_MANAGE_U';
    public static $HOUSING_APPLICATION_MANAGE_D = 'HOUSING_APPLICATION_MANAGE_D';

    public static $APPLICATION_TEMPLATE_C = 'APPLICATION_TEMPLATE_C';
    public static $APPLICATION_TEMPLATE_R = 'APPLICATION_TEMPLATE_R';
    public static $APPLICATION_TEMPLATE_U = 'APPLICATION_TEMPLATE_U';
    public static $APPLICATION_TEMPLATE_D = 'APPLICATION_TEMPLATE_D';

    public static $APPLICATION_FORMAT_C = 'APPLICATION_FORMAT_C';
    public static $APPLICATION_FORMAT_R = 'APPLICATION_FORMAT_R';
    public static $APPLICATION_FORMAT_U = 'APPLICATION_FORMAT_U';
    public static $APPLICATION_FORMAT_D = 'APPLICATION_FORMAT_D';

    public static $APPLICATION_SHOW_C = 'APPLICATION_SHOW_C';
    public static $APPLICATION_SHOW_R = 'APPLICATION_SHOW_R';
    public static $APPLICATION_SHOW_U = 'APPLICATION_SHOW_U';
    public static $APPLICATION_SHOW_D = 'APPLICATION_SHOW_D';


    public static $NOTICE_C = 'NOTICE_C';
    public static $NOTICE_R = 'NOTICE_R';
    public static $NOTICE_U = 'NOTICE_U';
    public static $NOTICE_D = 'NOTICE_D';

    public static $NOTICE_M_C = 'NOTICE_M_C';
    public static $NOTICE_M_R = 'NOTICE_M_R';
    public static $NOTICE_M_U = 'NOTICE_M_U';
    public static $NOTICE_M_D = 'NOTICE_M_D';


    public static $NOTICE_U_C = 'NOTICE_U_C';
    public static $NOTICE_U_R = 'NOTICE_U_R';
    public static $NOTICE_U_U = 'NOTICE_U_U';
    public static $NOTICE_U_D = 'NOTICE_U_D';


    public static $CREATE_NOTICE_C = 'APPLICATION_TEMPLATE_C';
    public static $CREATE_NOTICE_R = 'APPLICATION_TEMPLATE_R';
    public static $CREATE_NOTICE_U = 'APPLICATION_TEMPLATE_U';
    public static $CREATE_NOTICE_D = 'APPLICATION_TEMPLATE_D';

    public static $NOTICE_SHOW_C = 'NOTICE_SHOW_C';
    public static $NOTICE_SHOW_R = 'NOTICE_SHOW_R';
    public static $NOTICE_SHOW_U = 'NOTICE_SHOW_U';
    public static $NOTICE_SHOW_D = 'NOTICE_SHOW_D';


     public static$CREATE_COMPLAIN_C = 'CREATE_COMPLAIN_C';
     public static$CREATE_COMPLAIN_R = 'CREATE_COMPLAIN_R';
     public static$CREATE_COMPLAIN_U = 'CREATE_COMPLAIN_U';
     public static$CREATE_COMPLAIN_D = 'CREATE_COMPLAIN_D';
   
    public static $COMPLAIN_M_C = 'COMPLAIN_M_C';
    public static $COMPLAIN_M_R = 'COMPLAIN_M_R';
    public static $COMPLAIN_M_U = 'COMPLAIN_M_U';
    public static $COMPLAIN_M_D = 'COMPLAIN_M_D';

    public static $COMPLAIN_U_C = 'COMPLAIN_U_C';
    public static $COMPLAIN_U_R = 'COMPLAIN_U_R';
    public static $COMPLAIN_U_U = 'COMPLAIN_U_U';
    public static $COMPLAIN_U_D = 'COMPLAIN_U_D';

    public static $COMPLAIN_SHOW_C = 'COMPLAIN_SHOW_C';
    public static $COMPLAIN_SHOW_R = 'COMPLAIN_SHOW_R';
    public static $COMPLAIN_SHOW_U = 'COMPLAIN_SHOW_U';
    public static $COMPLAIN_SHOW_D = 'COMPLAIN_SHOW_D';

   public static $APPLY_C='APPLY_C';
   public static $APPLY_R='APPLY_R';
   public static $APPLY_U='APPLY_U';
   public static $APPLY_D='APPLY_D';

      public static $APPLY_FOR_SEAT_C='APPLY_FOR_SEAT_C';
   
      public static $APPLY_FOR_SEAT_R='APPLY_FOR_SEAT_R';
      public static $APPLY_FOR_SEAT_U='APPLY_FOR_SEAT_U';
      public static $APPLY_FOR_SEAT_D='APPLY_FOR_SEAT_D';

       public static $VIEW_APPLICANTS_C='VIEW_APPLICANTS_C';
       public static $VIEW_APPLICANTS_R='VIEW_APPLICANTS_R';
       public static $VIEW_APPLICANTS_U='VIEW_APPLICANTS_U';
       public static $VIEW_APPLICANTS_D='VIEW_APPLICANTS_D';
   

  public static $INTERVIEW_C='INTERVIEW_C';
  public static $INTERVIEW_R='INTERVIEW_R';
  public static $INTERVIEW_U='INTERVIEW_U';
  public static $INTERVIEW_D='INTERVIEW_D';

    public static $BLACKLIST_C = 'BLACKLIST_C';
    public static $BLACKLIST_R = 'BLACKLIST_R';
    public static $BLACKLIST_U = 'BLACKLIST_U';
    public static $BLACKLIST_D = 'BLACKLIST_D';

    public static $HISTORY_C='HISTORY_C';
    public static $HISTORY_R='HISTORY_R';
    public static $HISTORY_U='HISTORY_U';
    public static $HISTORY_D='HISTORY_D';

    public static $ISSUE_C='ISSUE_C';
    public static $ISSUE_R='ISSUE_R';
    public static $ISSUE_U='ISSUE_U';
    public static $ISSUE_D='ISSUE_D';

    public static $ISSUE_U_C = 'ISSUE_U_C';
    public static $ISSUE_U_R = 'ISSUE_U_R';
    public static $ISSUE_U_U = 'ISSUE_U_U';
    public static $ISSUE_U_D = 'ISSUE_U_D';


    public static $HALL_PERMISSION_C = 'HALL_PERMISSION_C';
    public static $HALL_PERMISSION_R = 'HALL_PERMISSION_R';
    public static $HALL_PERMISSION_U = 'HALL_PERMISSION_U';
    public static $HALL_PERMISSION_D = 'HALL_PERMISSION_D';



        public static $ISSUE_USER_C = 'ISSUE_USER_C';
    public static $ISSUE_USER_R = 'ISSUE_USER_R';
    public static $ISSUE_USER_U = 'ISSUE_USER_U';
    public static $ISSUE_USER_D = 'ISSUE_USER_D';
    


}

class PageUtil{

    public static $DISCUSSION_CAT='discussion_category.php';
    public static $DISCUSSION='discussion.php';
    public static $DISCUSSION_COMMENT='discussion_comment.php';
    public static $DISCUSSION_SEARCH='discussion_search.php';
    public static $DISCUSSION_ANSWERED='discussion_answered.php';
    public static $DISCUSSION_UNANSWERED='discussion_unanswered.php';
    public static $DISCUSSION_LIST='discussion_list.php';
    public static $DISCUSSION_RECENT='discussion_recent.php';

    public static $HALL='hall.php';

    public static $ERROR='error.php';
    public static $HOME='home.php'; 
    public static $LOGIN='login.php';

    
    public static $PERMISSION='permission.php';
    public static $ROLE='role.php';
  
    public static $DISCIPLINE='discipline.php';
    public static $SCHOOL='school.php';
    public static $POSITION='position.php';

    public static $HOUSING_TYPE='housing_type.php';
    public static $HOUSING_M='housing.php';
    public static $HOUSING_ROOM='housing_room.php';
    public static $HOUSING_DETAIL='housing_details.php';
    public static $HOUSING_ROOM_ASSIGN='housing_room_assign.php';
    public static $HOUSING_SEARCH='housing_search.php';
    public static $HOUSING_APPLICATION = 'housing_application.php';
    public static $HOUSING_APPLICATION_MANAGE = 'housing_application_manage.php';
    public static $APPLICATION_TEMPLATE = 'application_template.php';
    public static $APPLICATION_FORMAT = 'application_format.php';
    public static $APPLICATION_SHOW = 'application_show.php';

    public static $USER='user.php';
    public static $USER_NEW='user_new.php';
    public static $USER_DETAILS='user_details.php';
    public static $USER_SEARCH='user_search.php';
    public static $USER_FORGOT_PASSWORD='forgot_password.php';

    public static $NOTICE='notice.php';

    //public static $MANAGE_NOTICE='managenotice.php';

    public static $VIEW_NOTICE='housing_notice_view.php';
    public static $CREATE_NOTICE='create_notice.php';
    public static $NOTICE_SHOW = 'notice_show.php';
     public static $SEARCH_NOTICE='search_notice.php';
     
      public static $CREATE_COMPLAIN='create_complain.php';
      public static $VIEW_COMPLAIN='view_complain.php';
       public static $COMPLAIN_SHOW = 'complain_show.php';
       public static $USER_DETAILS_NEW='user_details_new.php';
       public static $APPLY_FOR_SEAT='apply_for_seat.php';
       public static $VIEW_APPLICANTS='view_applicants.php';
       public static $INTERVIEW='interview.php';
       public static $CREATE_BLACKLIST='create_blacklist.php';
       public static $HISTORY='history.php';
       public static $ATTACHMENT_SHOW = 'attachmentview.php';
       public static $ISSUE='issue.php';
       public static $CREATE_ISSUE='create_issue.php';
       public static $INTERVIEW_LIST='interview_list.php';
       public static $VIEW_ISSUE='view_issue.php';
       public static $ISSUE_SHOW = 'issue_show.php';
       public static $SEARCH_BLACKLIST='search_blacklist.php';
       public static $VIEW_APPLICANTS_MANAGER='view_applicants_manager.php';
       public static $HOUSING_NEW='housing_new.php';
       public static $HALL_PERMISSION='hall_permission.php';
       public static $CREATE_ISSUE_USER='create_issue_user.php';




}

class RouteUtil{

    private static $s_Routes; //The single instance
    private static $s_instance; //The single instance


   private function __construct(){
        
         self::$s_Routes = array();

        //add new page and routing address here always

         self::$s_Routes[PageUtil::$DISCUSSION_CAT]  =  "modules/forum/ui/view.discussionCategory.inc";
         self::$s_Routes[PageUtil::$DISCUSSION]      =  "modules/forum/ui/view.discussion.inc";
         self::$s_Routes[PageUtil::$DISCUSSION_COMMENT] = "modules/forum/ui/view.comment.inc";
         self::$s_Routes[PageUtil::$DISCUSSION_LIST]   = "modules/forum/ui/view.discussionList.inc";
         self::$s_Routes[PageUtil::$DISCUSSION_SEARCH]   = "modules/forum/ui/view.searchDiscussion.inc";
         self::$s_Routes[PageUtil::$DISCUSSION_RECENT]  = "modules/forum/ui/view.mostRecent.inc";
         self::$s_Routes[PageUtil::$DISCUSSION_ANSWERED]  = "modules/forum/ui/view.answered.inc";
         self::$s_Routes[PageUtil::$DISCUSSION_UNANSWERED]  = "modules/forum/ui/view.unanswered.inc";


         self::$s_Routes[PageUtil::$HALL]  = "modules/hall/ui/view.hall.inc";

         self::$s_Routes[PageUtil::$HOME]             =   "modules/dashboard/ui/view.home.inc";
         self::$s_Routes[PageUtil::$LOGIN]            =   "modules/dashboard/ui/view.login.inc";

         self::$s_Routes[PageUtil::$ROLE]   =   "modules/user/ui/view.role.inc";
         self::$s_Routes[PageUtil::$DISCIPLINE]       =   "modules/user/ui/view.discipline.inc";  
         self::$s_Routes[PageUtil::$PERMISSION]       =   "modules/user/ui/view.permission.inc";
         self::$s_Routes[PageUtil::$POSITION]         =   "modules/user/ui/view.position.inc";
         self::$s_Routes[PageUtil::$SCHOOL]           =   "modules/user/ui/view.school.inc";

         self::$s_Routes[PageUtil::$USER] =   "modules/user/ui/view.user.inc";
         self::$s_Routes[PageUtil::$USER_DETAILS] =   "modules/user/ui/view.user_details.inc";
         self::$s_Routes[PageUtil::$USER_NEW] =   "modules/user/ui/view.user_new.inc";
         self::$s_Routes[PageUtil::$USER_SEARCH] =   "modules/user/ui/view.user_search.inc";
         self::$s_Routes[PageUtil::$USER_FORGOT_PASSWORD] =   "modules/user/ui/view.forgot_password.inc";

         //Housing Routes
         self::$s_Routes[PageUtil::$HOUSING_TYPE]  = "/modules/housing/ui/view.housingType.inc";
         self::$s_Routes[PageUtil::$HOUSING_M]  = "/modules/housing/ui/view.housing.inc";
         self::$s_Routes[PageUtil::$HOUSING_ROOM] = "/modules/housing/ui/view.housingRoom.inc";
         self::$s_Routes[PageUtil::$HOUSING_DETAIL] = "/modules/housing/ui/view.housingDetails.inc";
         self::$s_Routes[PageUtil::$HOUSING_ROOM_ASSIGN] = "/modules/housing/ui/view.housingRoomAssign.inc";
         self::$s_Routes[PageUtil::$HOUSING_SEARCH] = "/modules/housing/ui/view.housingSearch.inc";
         
         self::$s_Routes[PageUtil::$HOUSING_APPLICATION] = "/modules/application/ui/view.housingApplication.inc";
         self::$s_Routes[PageUtil::$HOUSING_APPLICATION_MANAGE] = "/modules/application/ui/view.housingApplicationManage.inc";
         self::$s_Routes[PageUtil::$APPLICATION_TEMPLATE] = "/modules/application/ui/view.applicationTemplate.inc";
         self::$s_Routes[PageUtil::$APPLICATION_FORMAT] = "/modules/application/ui/view.applicationFormat.inc";
         self::$s_Routes[PageUtil::$APPLICATION_SHOW] = "/modules/application/ui/view.applicationShow.inc";
 

        //the page not found will redirect to error page
         self::$s_Routes[PageUtil::$ERROR] = "modules/dashboard/ui/view.error.inc";
         // self::$s_Routes[PageUtil::$MANAGE_NOTICE] = "modules/notice/ui/view.viewNotice.php";
         self::$s_Routes[PageUtil::$VIEW_NOTICE] = "modules/notice/ui/view.viewNotice.inc";
          self::$s_Routes[PageUtil::$CREATE_NOTICE] = "modules/notice/ui/view.createNotice.inc";
           self::$s_Routes[PageUtil::$NOTICE_SHOW] = "modules/notice/ui/view.noticeShow.inc";
            self::$s_Routes[PageUtil::$SEARCH_NOTICE] = "modules/notice/ui/view.searchNotice.inc";
      self::$s_Routes[PageUtil::$CREATE_COMPLAIN] = "modules/complain/ui/view.createComplain.inc";
      self::$s_Routes[PageUtil::$VIEW_COMPLAIN] = "modules/complain/ui/view.viewComplain.inc";
       self::$s_Routes[PageUtil::$COMPLAIN_SHOW] = "modules/complain/ui/view.complainShow.inc";
        self::$s_Routes[PageUtil::$USER_DETAILS_NEW] =   "modules/user/ui/view.user_details_new.inc";

         self::$s_Routes[PageUtil::$APPLY_FOR_SEAT] =   "modules/apply/ui/view.apply_for_seat.inc";
self::$s_Routes[PageUtil::$VIEW_APPLICANTS] =   "modules/apply/ui/view.viewApplicants.inc";
self::$s_Routes[PageUtil::$INTERVIEW] = "modules/apply/ui/view.interview.inc";

self::$s_Routes[PageUtil::$CREATE_BLACKLIST] = "modules/blacklist/ui/view.createblacklist.inc";
self::$s_Routes[PageUtil::$HISTORY] = "modules/housing/ui/view.history.inc";
self::$s_Routes[PageUtil::$ATTACHMENT_SHOW] = "modules/notice/ui/view.attachmentview.inc";
self::$s_Routes[PageUtil::$CREATE_ISSUE] = "modules/issue/ui/view.createIssue.inc";

self::$s_Routes[PageUtil::$INTERVIEW_LIST] = "modules/apply/ui/view.interviewList.inc";
self::$s_Routes[PageUtil::$VIEW_ISSUE] = "modules/issue/ui/view.viewIssue.inc";

 self::$s_Routes[PageUtil::$ISSUE_SHOW] = "modules/issue/ui/view.issueShow.inc";
 self::$s_Routes[PageUtil::$SEARCH_BLACKLIST] = "modules/blacklist/ui/view.searchBlacklist.inc";
 self::$s_Routes[PageUtil::$VIEW_APPLICANTS_MANAGER] =   "modules/apply/ui/view.viewApplicantsmanager.inc";
 self::$s_Routes[PageUtil::$HOUSING_NEW]  = "/modules/housingnew/ui/view.housingnew.inc";

 self::$s_Routes[PageUtil::$HALL_PERMISSION]  = "/modules/housingnew/ui/view.hallPermission.inc";
 self::$s_Routes[PageUtil::$CREATE_ISSUE_USER] = "modules/issue/ui/view.createIssueUser.inc";




      
    }

    public static function getInstance() {
        if(!self::$s_instance) { // If no instance then make one
            self::$s_instance = new self();
        }
        return self::$s_instance;
    }

    public static function get($Page){

        $Page = strtolower(trim($Page)); 

        if(array_key_exists($Page, self::$s_Routes)){
        
            return self::$s_Routes[$Page];
        }
        else{
        
            return self::$s_Routes[PageUtil::$ERROR]; 
        }
    }

}

class MiddlewareUtil{

    private static $s_Routes; //The single instance
    private static $s_instance; //The single instance


    private function __construct(){
        
         self::$s_Routes = array();

        //add which page should be successfully logged before getting to this page
        //example: login.php should be successfully logged in to get to home.php
         self::$s_Routes[PageUtil::$HOME]   =  PageUtil::$LOGIN ;

   
         self::$s_Routes[PageUtil::$USER]   =  PageUtil::$LOGIN ;
         self::$s_Routes[PageUtil::$USER_DETAILS]   =  PageUtil::$LOGIN ;

         self::$s_Routes[PageUtil::$HALL]   =  PageUtil::$LOGIN ;

         self::$s_Routes[PageUtil::$HOUSING_TYPE]   =  PageUtil::$LOGIN ;
        
         self::$s_Routes[PageUtil::$HOUSING_M]   =  PageUtil::$LOGIN ;
         self::$s_Routes[PageUtil::$HOUSING_ROOM]   =  PageUtil::$LOGIN ;
         self::$s_Routes[PageUtil::$HOUSING_DETAIL]   =  PageUtil::$LOGIN ;
         self::$s_Routes[PageUtil::$HOUSING_ROOM_ASSIGN]   =  PageUtil::$LOGIN ;
         self::$s_Routes[PageUtil::$HOUSING_SEARCH]   =  PageUtil::$LOGIN ;
         self::$s_Routes[PageUtil::$HOUSING_APPLICATION]   =  PageUtil::$LOGIN ;
         self::$s_Routes[PageUtil::$HOUSING_APPLICATION_MANAGE]   =  PageUtil::$LOGIN ;
         self::$s_Routes[PageUtil::$APPLICATION_TEMPLATE]   =  PageUtil::$LOGIN ;
         self::$s_Routes[PageUtil::$APPLICATION_FORMAT]   =  PageUtil::$LOGIN ;
         self::$s_Routes[PageUtil::$APPLICATION_SHOW]   =  PageUtil::$LOGIN ;
         

         self::$s_Routes[PageUtil::$ROLE]   =  PageUtil::$LOGIN ;
         self::$s_Routes[PageUtil::$PERMISSION]   =  PageUtil::$LOGIN ;
         

         self::$s_Routes[PageUtil::$DISCIPLINE]   =  PageUtil::$LOGIN ;

           self::$s_Routes[PageUtil::$CREATE_NOTICE]   =  PageUtil::$LOGIN ;
             self::$s_Routes[PageUtil::$NOTICE_SHOW]   =  PageUtil::$LOGIN ;
               self::$s_Routes[PageUtil::$SEARCH_NOTICE]   =  PageUtil::$LOGIN ;
                self::$s_Routes[PageUtil::$VIEW_NOTICE]   =  PageUtil::$LOGIN ;
                 // self::$s_Routes[PageUtil::$CREATE_COMPLAIN]   =  PageUtil::$LOGIN ;
                self::$s_Routes[PageUtil::$COMPLAIN_SHOW]   =  PageUtil::$LOGIN ;

                self::$s_Routes[PageUtil::$APPLY_FOR_SEAT]   =  PageUtil::$LOGIN ;
                self::$s_Routes[PageUtil::$VIEW_APPLICANTS]   =  PageUtil::$LOGIN ;
                self::$s_Routes[PageUtil::$CREATE_BLACKLIST]   =  PageUtil::$LOGIN ;
                self::$s_Routes[PageUtil::$HISTORY]   =  PageUtil::$LOGIN ;
                self::$s_Routes[PageUtil::$ATTACHMENT_SHOW]   =  PageUtil::$LOGIN ;
                self::$s_Routes[PageUtil::$CREATE_ISSUE]   =  PageUtil::$LOGIN ;
                self::$s_Routes[PageUtil::$VIEW_APPLICANTS_MANAGER]   =  PageUtil::$LOGIN ;
                self::$s_Routes[PageUtil::$HOUSING_NEW]   =  PageUtil::$LOGIN ;
   
    }

    public static function getInstance() {
        if(!self::$s_instance) { // If no instance then make one
            self::$s_instance = new self();
        }
        return self::$s_instance;
    }

    private static function isAvailable($Page){

        $Page = strtolower(trim($Page)); 

        //if the page is refereneced in the middleware
        if(array_key_exists($Page, self::$s_Routes)){
            
            return true;
        }
        else{
        
            return false; 
        }
    }

    public static function get($Page){


        //if page is referenced
        if(self::isAvailable($Page)){
            //start session and check whether the middleware is successfully crossed

            if (session_status() == PHP_SESSION_NONE) {
                session_start();
            }

            // other send initial page: example if logged out then go to login.php page
            return isset($_SESSION[self::$s_Routes[$Page]])? $Page: self::$s_Routes[$Page]; 

        }else{
            // if no middleware then just go on with the current request
            return $Page;
        }
    }

}

//finding different partse of an url
    function unparse_url($parsed_url) { 
        $scheme   = isset($parsed_url['scheme']) ? $parsed_url['scheme'] . '://' : ''; 
        $host     = isset($parsed_url['host']) ? $parsed_url['host'] : ''; 
        $port     = isset($parsed_url['port']) ? ':' . $parsed_url['port'] : ''; 
        $user     = isset($parsed_url['user']) ? $parsed_url['user'] : ''; 
        $pass     = isset($parsed_url['pass']) ? ':' . $parsed_url['pass']  : ''; 
        $pass     = ($user || $pass) ? "$pass@" : ''; 
        $path     = isset($parsed_url['path']) ? $parsed_url['path'] : ''; 
        $query    = isset($parsed_url['query']) ? '?' . $parsed_url['query'] : ''; 
        $fragment = isset($parsed_url['fragment']) ? '#' . $parsed_url['fragment'] : ''; 

        //extracting the page name such as user.php from the url
        $page = substr($path, strrpos($path,'/')+1,strrpos($path,'.php')-strrpos($path,'/')+strlen('.php'));

        return $page;
        //return "$scheme$user$pass$host$port$path$query$fragment"; 
} 


//applying middleware such as login.php comes before home.php
    function apply_middleware($page) { 
     
        // checking whtether there is any middleware     
        $page=MiddlewareUtil::get($page);   

        return $page;
         
    }

//finding different partse of an url
    function apply_routing(&$page) { 
     
        //looking for the extracted page in the route list
        $page=RouteUtil::get($page);

        return true;
    }




MiddlewareUtil::getInstance();
RouteUtil::getInstance();

?>