<?php

include_once MODULES_NOTICE_BLADE.'view.searchNotice.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';


?>


<div class="panel panel-default">
    
    <div class="panel-heading">Search Notice</div>
    
	    <div class="panel-body">

			<div id="form">
				<form method="post" class="form-horizontal">

					

					<div class="form-group">
		              	<label class="control-label col-sm-4" for="selectedField">Search Field:</label>
		              	<div class="col-sm-6">								   						    
								<select name="selectedField" class="form-control" id="selectedField" required>

									<option selected disabled>Select Search Criteria</option>
									<option value="subject">Subject</option>
									<option value="app_date" >Date</option>
									
									
								</select>	
						</div>
					</div>


					<div class="form-group">
		              	<label class="control-label col-sm-4" for="txtSearch">Search Text</label>
		              	<div class="col-sm-6">
		              	<input type="" name="txtSearch" class="form-control" placeholder="Input the search text" required/>

					  	</div>
					</div>
				
					  
			        <div class="form-group">        
		              <div class="col-sm-offset-2 col-sm-10">
		    
							<button type="submit" value="search" name="search">Search</button>

					   </div>
		            </div> 
				
				</form>
				
			</div>
		</div>

		<div class="panel-body">

		<table class="table table-bordered">
		<?php
		//search clicked and result loaded
		if(isset($_POST['search']) && isset($ResultSearch))
		{
		
		
		//if DAO access is successful to load all the users then show them one by one
		if($ResultSearch->getIsSuccess()){

			$Noticelist = $ResultSearch->getResultObject();
		?>
			<tr>
				 <th>Subject</th>
                    <th>Submission Date</th>
                    <th>Notice</th>
                    <th>Attahment</th>
				
				
			</tr>
			<?php


                    $Result = $_SearchNoticeBAO->getNotice($SearchField,$SearchText);
                    if ($Result->getIsSuccess()) {
                        $NoticeList = $Result->getResultObject();
                        for ($i=0; $i < sizeof($NoticeList); $i++) { 
                            $Notice = $NoticeList[$i];

                            ?>
                            <tr>
                            
                         <td><?php echo $Notice->getSubject();?></td>
                            <td><?php echo $Notice->getDate();?></td>
                            <td><a href="notice_show.php?view=<?php echo $Notice->getId();?>" onclick="return ; ">Notice</a></td>
                             <td><a class="btn btn-primary" href="<?php echo "".$Notice->getLinks(); ?>" role="button">Attachment</a>
                         </td>

                            </tr>
                            <?php
                        }
                    }

                    ?>
			    	 	
			    	 </td>
				    
				    
				    

				    </tr>
		    <?php

			}

		}

		
		
		

		?>
		</table>
		</div>


		







