



<?php
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once MODULES_NEWHOUSING_BLADE.'view.hallPermission.blade.inc';
include_once MODULES_HOUSING_BLADE.'view.housingRoomAssign.blade.inc';

//include_once MODULES_NOTICE_BLADE.'view.viewNotice.blade.inc';








?>
<script type="text/javascript">
function Confirm(form){
alert(" submit successfully!"); 
form.submit();
}
</script>
<?php
            $var = '';
            $Result = $_HousingRoomAssignBAO->getNameFromId($_SESSION["Id"]);

                //if DAO access is successful to load all the Roles then show them one by one

            if($Result->getIsSuccess()){

                $Housing = $Result->getResultObject();             

                $var = $Housing->getName();

            }
             
        ?>
        <h3><u><?php echo $var ?></u></h3>

<div class="panel col-md-10 col-md-offset-1" style="font-size: 16px; border-top: outset; border-left: outset;
                                border-bottom: inset; border-right: inset; margin-top: 40px">
    <div class="panel-heading" align="center">
        <h3><u>Hall Permission</u></h3>
    </div>
   
    <div class="panel-body" align="center">
        
           <form method="post" >
            
             <label class="panel-heading" for="idd">ID:</label>    
              
                    
                        <textarea class="form-control" name="idd" style="width:60%; height: 50px; font-size: 15px"
                       
                                  required><?php if(isset($_GET['edit'])) echo $getROW->getIdd();  ?></textarea>









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
                                <button type="submit" name="Post" class="btn btn-primary">Add</button>
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


            $Result = $_HallPermissionBAO->getAllHallPermission($_SESSION["Id"]);

            //if DAO access is successful to load all Type then show them one by one
            if($Result->getIsSuccess()){

                $HallPermissionList = $Result->getResultObject();
            ?>
                <tr>
                    <th>ID</th>
                    <th></th>
                    <th></th>
                </tr>
                <?php
                for($i = 0; $i < sizeof($HallPermissionList); $i++) {
                    $HallPermission = $HallPermissionList[$i];
                    ?>
                    <tr>
                        <td><?php echo $HallPermission->getIdd(); ?></td>
                       
                         

                        <td><a href="hall_permission.php?id=<?php echo $HallPermission->getHallId();?>&edit=<?php echo $HallPermission->getId(); ?>" onclick="return confirm('Are You Sure to edit !'); " >Edit</a></td>
                         <td><a href="hall_permission.php?id=<?php echo $HallPermission->getHallId();?>&dell=<?php echo $HallPermission->getId(); ?>" onclick="return confirm('Are You Sure to Delete !'); " >Delete</a></td>
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

