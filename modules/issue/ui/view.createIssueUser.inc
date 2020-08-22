<?php

include_once MODULES_ISSUE_BLADE.'view.createIssue.blade.inc';
//include_once MODULES_NOTICE_BLADE.'view.viewNotice.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';




?>


<script type="text/javascript">
function Confirm(form){
alert("Notice submit successfully!"); 
form.submit();
}
</script>

<div class="panel col-md-10 col-md-offset-1" style="font-size: 16px; border-top: outset; border-left: outset;
                                border-bottom: inset; border-right: inset; margin-top: 50px">
    <div class="panel-heading" align="center">
        <h3><u>Create Issues</u></h3>
    </div>
   
    <div class="panel-body" align="center">
        
           <form method="post" enctype="multipart/form-data">
            
             <label class="panel-heading" for="subject">Subject:</label>    
              
                    
                        <textarea class="form-control" name="subject" style="width:70%; height: 50px; font-size: 15px"
                       
                                  required><?php if(isset($_GET['edit'])) echo $getROW->getSubject();  ?></textarea>


    <div id='message'></div>
    <div class="panel-body" align="center">
       <label class="" for="subject">Issue:</label>
        
            <form method="post" enctype="multipart/form-data">
            
                
              
                    
                        <textarea class="form-control" name="body" style="width:70%; height: 600px; font-size: 16px"
                        
                                  required><?php if(isset($_GET['edit'])) echo $getROW->getBody();  ?>
                                         




</textarea>
                   
               <!-- </div> -->
               
              <form method="post" enctype="multipart/form-data">
                    <!-- <input type="file" name="link" id="linkId"> -->


                    <input type="file" name="fileToUpload" id="fileToUpload">

            

               
                <div class="form-group">
                  <div class="">
                            <?php
                            if(isset($_GET['edit']))
                            {
                                ?>
                                <button type="submit" name="update" class="btn btn-primary">Update</button>
                                <?php
                            }
                            else
                            {
                                ?>
                                <button type="submit" name="Post" class="btn btn-primary">Post</button>
                                <?php
                            }
                            ?>
                    </div>
                </div>
                


            </form>
           
    </div>
</div>
 


 <div class="panel-body">

        <table class="table table-bordered">

            <?php


            $Result = $_CreateIssueBAO->getAllIssue();

            //if DAO access is successful to load all Type then show them one by one
            if($Result->getIsSuccess()){

                $CreateIssueList = $Result->getResultObject();
            ?>
                <tr>
                    <th>Subject</th>
                    <th>Issue</th>
                    <th>Link</th>

                
                </tr>
                <?php
                for($i = 0; $i < sizeof($CreateIssueList); $i++) {
                    $CreateIssue = $CreateIssueList[$i];
                    ?>
                    <tr>
                        <td><?php echo $CreateIssue->getSubject(); ?></td>
                         <td><a href="Issue_show.php?view=<?php echo $CreateIssue->getId();?>" onclick="return ; ">Issue</a></td>
                         <td><a class="btn btn-primary" href="<?php echo "".$CreateIssue->getLinks(); ?>" role="button">Attachment</a>
                         </td>

                       
                       
                    </tr>
                <?php

                }

            }
            else{

                echo $Result->getResultObject(); //giving failure message
            }

            ?>
        </table>
    </div>




