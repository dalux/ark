<?php

namespace App\Controller;

use Ark\Core\Sailor;
use Ark\Toolkit\SQLBuilder;

class Index extends Sailor
{

	function index()
	{
		while (true) {
			$sql = SQLBuilder::select('oci')
					->from(array('a' => 'tmp_yihaodian_spbs'), array('spbs'))
					->where('rownum<200');
			if (!$result = $this->oracle->fetchAll($sql)) {
				echo '['. date('Y-m-d H:i:s'). '] 所有数据处理完毕'. PHP_EOL;
				break;
			}
			foreach ($result as $val) {
				$sql = SQLBuilder::select('oci')
						->from(array('a' => 'bm_jbxxk'), array('spbs',  'sm'=> '{{substr(sm, 0, 256)}}', 'isbn', 'zyz', 'my_dj', 'cbrq' => "{{to_char(a.cbrq, 'yyyy-mm-dd')}}", 'ysny' => "{{to_char(a.ysny, 'yyyy-mm-dd')}}", 'yc', 'bc'))
						->joinLeft(array('b' => 'bm_cbsbmb'), 'a.bb=b.bb', array('cbsmc'))
						->joinLeft(array('c' => 'bm_kbbmb'), 'a.kb=c.bh', array('kb' => 'mc'))
						->joinLeft(array('d' => 'bm_fjxxk'), 'a.spbs=d.spbs', array('ys', 'zs'))
						->where('a.spbs=?', $val['spbs']);
				$detail = $this->oracle->fetch($sql);
				$sm = explode('/', $detail['sm']);
				$zyz = str_replace(array('（', '）', '//'), array('(', ')', '/'), $detail['zyz']);
				$data = array(
					'title'=> str_replace(array('\\', '\''), '', $sm[0]),
					'isbn'=> $detail['isbn'],
					'author'=> mb_substr(str_replace(array('\\', '\''), '', $zyz), 0, 64),
					'dj'=> $detail['my_dj'],
					'publisher'=> $detail['cbsmc'],
					'publish_date'=> $detail['cbrq'],
					'print_date'=> $detail['ysny'],
					'publish_num'=> $detail['bc'],
					'print_num'=> $detail['yc'],
					'folio'=> trim($detail['kb']),
					'page_count'=> (int)$detail['ys'],
					'word_count'=> (int)$detail['zs'],
					'bkspbs'=> $val['spbs']
				);
				$data = array_filter($data);
				$sql = SQLBuilder::insert('mysql')->into('base_items', $data);
				//echo $sql.PHP_EOL;exit;
				$this->mysql->query($sql);
				$sql = SQLBuilder::delete('oci')->from('tmp_yihaodian_spbs')->where('spbs=?', $val['spbs']);
				$this->oracle->query($sql);
				echo '['. date('Y-m-d H:i:s'). '] 商品['. $val['spbs']. ']已经转移完毕'. PHP_EOL;
			}
		}
	}

}
