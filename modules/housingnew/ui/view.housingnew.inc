




<?php
include_once MODULES_HOUSING_BLADE.'view.housing.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';
include_once COMMON.'class.common.user.inc';
include_once MODULES_HOUSING_BLADE.'view.housingDetails.blade.inc';
include_once MODULES_USER.'ui/blade/view.user_details.blade.inc';


?>



<div class="panel-body">

			<table class="table table-bordered">

			<?php
			
			$Id= $userPositions->getUniversityID();
			$Result0= $_HousingDetailsBAO->getHallIdFromId($Id);
			if ($Result0->getIsSuccess()) {
                        $list = $Result0->getResultObject();
                        for ($j=0; $j < sizeof($list); $j++) { 
                            $Hall = $list[$j];

						$Id= $Hall->getHallId();

						
						//echo $Id;?>



<?php  


$Result7 = $_HousingBAO->getNameFromId($Id);
							if ($Result7->getIsSuccess())
					    	 {


					    	 	?>


					    	 	<div class="panel-body">

		<table class="table table-bordered">

			<tr>
					<th>Housing Name</th>
					<th>Housing Type</th>
					<th>Floors</th>
					<th></th>
					<th></th>
					<th></th>
	
				</tr>


			<?php 
					    	 $house1 = $Result7->getResultObject();
					    	}
					    	 ?>
                              <h3><u><?php echo $house1->getName(); ?></u></h3>
                             <!-- <a href="hall_permission.php?id=<?php echo $Id ?>" onclick="return ; "> Permisson</a>
                             -->



                         
                         
                             
					    	 
					    	 




			<?php
							



			$Result = $_HousingBAO->getAllHousingById($Id);

			//if DAO access is successful to load all the Terms then show them one by one
			if($Result->getIsSuccess()){

				$HousingList = $Result->getResultObject();
			?> 
				<!--<tr>
					<th>Housing Name</th>
					<th>Housing Type</th>
					<th>Floors</th>
	
				</tr>

			-->
				<?php
				for($i = 0; $i < sizeof($HousingList); $i++) {
					$Housing = $HousingList[$i];
					?>
				    <tr>
				    <td>
				    <a href="housing_room.php?view=<?php echo $Housing->getID();  ?>&h_id=<?php echo $Housing->getID(); ?>" onclick="return ; " > <?php echo $Housing->getName(); ?></a>
				    </td>
					    <td><?php $id = $Housing->getTypeId();
					    	$Result2 = $_HousingBAO->getNameFromTypeID($id);
					    	if ($Result2->getIsSuccess()) {

					    		$HousingType = $Result2->getResultObject();

					    		echo $HousingType->getName();
					    	}
					    	
					    	?>
					    		
					    </td>

					    <td><?php echo $Housing->getFloor(); ?></td>
					    <td><a href="housing_details.php?view=<?php echo $Housing->getID(); ?>&h_id=<?php echo $Housing->getID(); ?>" onclick="return;" >Details Add</a></td>
					    <td><a href="?edit=<?php echo $Housing->getID(); ?>" onclick="return confirm('Are You Sure to edit !'); " >Edit</a></td>
					    <td><a href="?del=<?php echo $Housing->getID(); ?>" onclick="return confirm('Are You Sure to delete!'); " >Delete</a></td>
				    </tr>
			    <?php

				}

			}

			else{

				echo $Result->getResultObject(); //giving failure message
			}
}
}
			?>
			</table>
		</div>

</div>