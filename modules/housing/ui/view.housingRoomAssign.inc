<?php

include_once MODULES_HOUSING_BLADE.'view.housingRoomAssign.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once COMMON.'class.common.user.inc';



$_SESSION["hid"] = $_GET['h_id'];
$_SESSION["rid"] = $_GET['r_id'];
//$_SESSION["id"] = $_GET['_id'];
//echo $_GET['_id'];

?>

<script>

    function addFunction(id) {
        var val=$('#pid').val();
        //var rid = $_SESSION["rid"].val();
        if(id.length==0){
            $('#addStudent').html("");
            $('#addStudent').style.border="0px";
            return;
        }
        xmlhttp=new XMLHttpRequest();
        xmlhttp.onreadystatechange=function () {
            if(this.readyState==4&&this.status==200){
                $('#addStudent').html(this.responseText);
                $('#addStudent').style.border="1px solid";
            }
        }
        xmlhttp.open("GET","./modules/housing/ui/addResponse.php?key="+id+"&pid="+val,true);
        xmlhttp.send();
    }
</script>


<div class="panel panel-default">
    
    <div class="panel-heading">Housing Room Assign</div>

    <div class="panel-heading" align="center">
        <?php
	        $var = '';
	        $Result = $_HousingRoomAssignBAO->getNameFromId($_SESSION["hid"]);

	            //if DAO access is successful to load all the Roles then show them one by one

	        if($Result->getIsSuccess()){

	            $Housing = $Result->getResultObject();             

	            $var = $Housing->getName();

	        }
	        echo $var;
        ?>
    </div>
    <div class="panel-heading" align="center">
        <?php
	        $var = 'Room No';
	        $Result = $_HousingRoomAssignBAO->getRoomNoFromId($_SESSION["rid"]);

	            //if DAO access is successful to load all the Roles then show them one by one

	        if($Result->getIsSuccess()){

	            $HousingRoom = $Result->getResultObject();             

	            $var = $var." : " .$HousingRoom->getRoomNo();

	        }
	        echo $var;
        ?>
    </div>
    
    <div class="panel-body">

		<div id="form">
			<form method="post" class="form-horizontal">
				<div class="form-group">
					<label for="student_add" class="control-label col-md-3 text-info">Add User:</label>
					<div class="col-md-5">
						<input type="search" name="student_add" id="student_add" class="form-control alert-info" onkeyup="addFunction(this.value);" placeholder="Search..." required>
					
					</div>
					
					<div id="addStudent" class="col-md-4" style="text-align: left"></div>
				
					
				</div>
				
				
				
	
		        <div class="form-group">        
	                <div class="col-sm-offset-2 col-sm-6">
	                	<?php

	                		$Result = $_HousingRoomAssignBAO->getNumberOfUsersFromRoom($_SESSION["hid"],$_SESSION["rid"]);
	                		if($Result->getIsSuccess()){

	                			$Result1 = $_HousingRoomAssignBAO->getTotalUserInRoom($_SESSION["hid"],$_SESSION["rid"]);
	                			if($Result->getIsSuccess()){
	                				if($_SESSION["countUsers"] < $_SESSION["totalUsers"]){?>


                					<button type="submit" name="save" class="btn btn-default">Assign</button>
								
								
									<?php }
									 else { 

									 	?>

											<label class="control-label" >No available seat in this Room</label>

									<?php }
								}
						 	} ?>
							
					</div>
				</div>	
			</form>
			
		</div>
	</div>

		<div class="panel-body">

			<table class="table table-bordered">

			<?php
			
			
			$Result = $_HousingRoomAssignBAO->getAllHousingRoomAssign($_SESSION["hid"],$_SESSION["rid"]);

			//if DAO access is successful to load all the Terms then show them one by one
			if($Result->getIsSuccess()){

				$HousingRoomAssignList = $Result->getResultObject();
			?> 
				<tr>
					<th>University ID</th>
					<th>Email</th>
					<th>First Name</th>
					<th>Last Name</th>
					<th> </th>
					<th> </th>

	
				</tr>
				<?php
					for($i = 0; $i < sizeof($HousingRoomAssignList); $i++) {

						$HousingRoomAssign = $HousingRoomAssignList[$i];

						$id = $HousingRoomAssign->getUserId();
	                    $Result2 = $_HousingRoomAssignBAO->getUserFromId($id);
	                    if ($Result2->getIsSuccess()) {

                                $User = $Result2->getResultObject();

						?>
					    <tr>
					    	
					    	<td><a href="user_details.php?id=<?php echo $User->getID();?>" onclick="return ; " > <?php 
					    	echo $User->getUniversityID(); ?></a>
					    	</td>

	                        <td><?php echo $User->getEmail();?></td>

	                        <td><?php echo $User->getFirstName();?></td>
	                        <td><?php echo $User->getLastName();?></td>
					    	
						    

						    <td><a href="?del=<?php echo $HousingRoomAssign->getUserId(); ?>&h_id=<?php echo $HousingRoomAssign->getHouseId(); ?>&r_id=<?php echo $HousingRoomAssign->getRoomId(); ?>" onclick="return confirm('Are You Sure to delete!'); " >Delete</a></td>
						   
						    	<td> <a href="history.php?id=<?php echo $User->getID();?>" onclick="return ; ">
						    	
						    	History
						    	</a>
						    </td>
					    </tr>

			    <?php

				}

			}
		}
			else{

				echo $Result->getResultObject(); //giving failure message
			}

			?>
			</table>
		</div>

</div>




