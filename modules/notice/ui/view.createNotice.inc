<?php

include_once MODULES_NOTICE_BLADE.'view.createNotice.blade.inc';
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
        <h3><u>Notice</u></h3>
    </div>
   
    <div class="panel-body" align="center">
        
           <form method="post" enctype="multipart/form-data">
            
             <label class="panel-heading" for="subject">Subject:</label>    
              
                    
                        <textarea class="form-control" name="subject" style="width:70%; height: 50px; font-size: 15px"
                       
                                  required><?php if(isset($_GET['edit'])) echo $getROW->getSubject();  ?></textarea>


    <div id='message'></div>
    <div class="panel-body" align="center">
       <label class="" for="subject">Notice:</label>
        
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


            $Result = $_CreateNoticeBAO->getAllNotice();

            //if DAO access is successful to load all Type then show them one by one
            if($Result->getIsSuccess()){

                $CreateNoticeList = $Result->getResultObject();
            ?>
                <tr>
                    <th>Subject</th>
                    <th>Notice</th>
                    <th>Link</th>

                    <th></th>
                    <th></th>
                </tr>
                <?php
                for($i = 0; $i < sizeof($CreateNoticeList); $i++) {
                    $CreateNotice = $CreateNoticeList[$i];
                    ?>
                    <tr>
                        <td><?php echo $CreateNotice->getSubject(); ?></td>
                         <td><a href="notice_show.php?view=<?php echo $CreateNotice->getId();?>" onclick="return ; ">Notice</a></td>
                         <td><a class="btn btn-primary" href="<?php echo "".$CreateNotice->getLinks(); ?>" role="button">Attachment</a>
                         </td>

                        <td><a href="?edit=<?php echo $CreateNotice->getId(); ?>" onclick="return confirm('Are You Sure to edit !'); " >Edit</a></td>
                        <td><a href="?del=<?php echo $CreateNotice->getID(); ?>" onclick="return confirm('Are You Sure to delete !'); " >Delete</a></td>
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




